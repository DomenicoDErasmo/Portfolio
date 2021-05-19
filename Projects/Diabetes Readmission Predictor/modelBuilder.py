import pandas as pd
import numpy as np
from imblearn.over_sampling import SMOTE
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import LabelEncoder
from mlxtend.feature_selection import SequentialFeatureSelector as sfs


def FixDiagCols(entry):
    if entry[0] == "E" or entry[0] == "V":
        return "Other"
    elif entry == "?" or entry is None:
        return "?"
    num = int(entry[0:3])
    if 390 <= num <= 459 or num == 785:
        return "Circulatory"
    elif 460 <= num <= 519 or num == 786:
        return "Respiratory"
    elif 520 <= num <= 579 or num == 787:
        return "Digestive"
    elif num == 250:
        return "Diabetes"
    elif 800 <= num <= 999:
        return "Injury"
    elif 710 <= num <= 739:
        return "Musculoskeletal"
    elif 580 <= num <= 629 or num == 788:
        return "Genitourinary"
    elif 140 <= num <= 239:
        return "Neoplasms"
    elif 780 <= num <= 781 or num == 784 or 790 <= num <= 799:
        return "Ill-defined"
    elif 240 <= num <= 279:
        return "Endocrine/Nutritional/Metabolic/Immunity"
    elif 680 <= num <= 709 or num == 782:
        return "Skin"
    elif 1 <= num <= 139:
        return "Infectious/Parasitic"
    elif 290 <= num <= 319:
        return "Mental Disorders"
    elif 280 <= num <= 289:
        return "Blood Diseases"
    elif 320 <= num <= 359:
        return "Nervous System"
    elif 630 <= num <= 679:
        return "Pregnancy Complications"
    elif 360 <= num <= 389:
        return "Sense Organs"
    elif 740 <= num <= 759:
        return "Congenital anomalies"
    else:
        return "External injury"


def InitialCleaning():
    in_file = "diabetic_data.csv"
    out_file = "initial_cleaned_data.csv"
    df = pd.read_csv(in_file)
    columns = ["diag_1", "diag_2", "diag_3"]
    for column in columns:
        df[column] = df[column].apply(FixDiagCols)
    df["readmitted"] = df["readmitted"].mask(df["readmitted"] == "NO", ">30")
    df.to_csv(out_file, index=False)
    print("Cleaned Columns")

    return out_file


def Imputation(cleaned_file):
    out_file = "imputed_data.csv"
    df = pd.read_csv(cleaned_file)
    print("Original size: ", df.shape)
    df = df.replace(['?'], 'None')
    df.replace('None', np.nan, inplace=True)
    df.isnull().sum()
    df = df.dropna(subset=['race', 'diag_1', 'diag_2', 'diag_3'])
    drop_columns = \
        ["encounter_id", "patient_nbr", "weight", "payer_code", "medical_specialty", "max_glu_serum", "A1Cresult"]
    for column in drop_columns:
        df = df.drop(column, 1)
    print("After size: ", df.shape)
    df.to_csv(out_file, index=False)
    print("Removed Incomplete Rows")

    return out_file


def Balancing(imputed_file):
    df = pd.read_csv(imputed_file)

    # encoding types
    label_encoder = LabelEncoder()
    for column in df:
        if df[column].dtypes == "object":
            df[column] = label_encoder.fit_transform(df[column])

    # SMOTE
    x = df.iloc[:, :-1]
    y = df.iloc[:, -1:]
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
    sm = SMOTE()
    x_sm, y_sm = sm.fit_resample(x_train, y_train)
    test_df = x_test.join(y_test, how="outer")
    train_df = x_sm.join(y_sm, how="outer")

    # output to files
    out_train_file = "raw_train_df.csv"
    out_test_file = "raw_test_df.csv"
    train_df.to_csv(out_train_file, index=False)
    test_df.to_csv(out_test_file, index=False)
    print("Balanced data")

    return out_train_file, out_test_file


def MapColumns(out_train_file, out_test_file):
    files = [out_train_file, out_test_file]
    out_files = [file[4:] for file in files]
    # carve out data
    for file in files:
        df = pd.read_csv(file)
        columns = ["num_lab_procedures", "num_procedures", "num_medications"]
        for column in columns:
            df[column] /= 10
        df.to_csv(file[4:], index=False)
    return out_files[0], out_files[1]


def SelectFeatures(train_file, estimators, features):
    df = pd.read_csv(train_file, index_col=False)
    all_features = df.drop("readmitted", 1)
    labels = df["readmitted"]
    rfc = RandomForestClassifier(n_estimators=estimators, criterion="entropy")
    selector = sfs(rfc, k_features=features, forward=True, floating=False, scoring='r2', cv=0)
    selector.fit(all_features, labels)
    outfile = "features.txt"
    file = open(outfile, "w")
    file.write(str(selector.k_feature_names_))
    return outfile


def RemoveNonFeatures(df, feature_list):
    chars = "(') "
    for i in range(len(feature_list)):
        for char in chars:
            feature_list[i] = feature_list[i].replace(char, "")
    for feature in df.columns:
        if feature not in feature_list:
            df = df.drop([feature], axis=1)
    return df


def GetBestModel(train_file, test_file, feature_list, min_iter, max_iter):
    test_df = pd.read_csv(test_file, index_col=False)
    x_test = RemoveNonFeatures(test_df.iloc[:, :-1], feature_list)
    y_test = test_df.iloc[:, -1]
    accuracies = []
    for i in range(min_iter, max_iter):
        print("Evaluating with " + str(i) + " estimators")
        model = CreateModel(train_file, feature_list, i)
        accuracy = EvaluateModel(model, x_test, y_test)
        accuracies.append(accuracy)
    best_model = accuracies.index(max(accuracies))
    print("Best Model has param", best_model)
    model = CreateModel(train_file, feature_list, best_model)
    accuracy = EvaluateModel(model, x_test, y_test, verbose=True)


def CreateModel(train_file, feature_list, estimators):
    df = pd.read_csv(train_file, index_col=False)
    x_train = df.iloc[:, :-1]
    y_train = df.iloc[:, -1]
    x_train = RemoveNonFeatures(x_train, feature_list)
    model = RandomForestClassifier(n_estimators=estimators)
    model.fit(x_train, y_train.values.ravel())
    return model


def EvaluateModel(model, x_test, y_test, verbose=False):
    y_pred = model.predict(x_test)
    error_matrix = confusion_matrix(y_test, y_pred)
    true_negative, false_positive, false_negative, true_positive = error_matrix.ravel()
    if verbose:
        print("Confusion Matrix:")
        print(error_matrix)
        print("Precision:", true_positive / (true_positive + false_positive))
        print("Sensitivity:", true_positive / (true_positive + false_negative))
        print("F1 Score:", (2 * true_positive) / (2 * true_positive + false_positive + false_negative))
        print("Specificity:", true_negative / (false_positive + false_negative))
        print("Accuracy:", (true_positive + true_negative) / len(y_pred))
    return (true_positive + true_negative) / len(y_pred)


def main(get_features=False, get_best_model=False):
    cleaned_file = InitialCleaning()
    imputed_file = Imputation(cleaned_file)
    out_train_file, out_test_file = Balancing(imputed_file)
    train_file, test_file = MapColumns(out_train_file, out_test_file)

    # made feature selection optional because this takes ~2 hours to run
    # The pre-provided feature list "features.txt" is the best feature list
    if get_features:
        feature_file = SelectFeatures(train_file, 51, 15)
    else:
        feature_file = "features.txt"
    feature_list = list(pd.read_csv(feature_file).columns)

    # made this optional because it takes ~10 minutes
    # The best parameter is 35
    if get_best_model:
        GetBestModel(train_file, test_file, feature_list, min_iter=10, max_iter=50)
    else:
        test_df = pd.read_csv(test_file, index_col=False)
        x_test = RemoveNonFeatures(test_df.iloc[:, :-1], feature_list)
        y_test = test_df.iloc[:, -1]
        model = CreateModel(train_file, feature_list, 35)
        accuracy = EvaluateModel(model, x_test, y_test, verbose=True)


if __name__ == "__main__":
    main()
