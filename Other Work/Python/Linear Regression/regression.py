"""
Domenico D'Erasmo
9 February 2021
L2 Regression.py
"""


import numpy as np
import os
import pandas as pd
import cProfile
import pstats
import matplotlib.pyplot as plt
from pathlib import Path


# Idea : Turn first 100 columns of CSV into matrix X, turn last column into vector y
# Create desired matrices and solve using the derived closed-form solution to the L2 problem
# Must find the weights by using training CSVs and then apply those weights to both training and test CSVs to find E's
# Note: the four 1000-100 CSVs all use the same 1000-100 test CSV


def PrintLines():
    print("------------------------------------------------")


def GetFolder(folder):
    resources_folder = Path(os.getcwd()).parent / "Resources"
    target_folder = resources_folder / folder
    return target_folder


def SetTrainingData(training_folder):
    training_data = {}
    for file in os.listdir(training_folder):
        training_data[file] = GetDataFromFolder(training_folder, file)
        training_data[file]["weights"] = GetWeights(training_data[file])
        training_data[file]["errors"] = GetMSEs(training_data, file)
    return training_data


def GetDataFromFolder(folder, file):
    file_data = {}
    complete_path = os.path.join(folder, file)
    data = np.loadtxt(open(complete_path, "rb"), delimiter=",")
    file_data["x"] = data[:, :-1]
    file_data["y"] = data[:, -1]
    return file_data


def GetWeights(training_data):
    all_weights = []
    for param in range(0, 151):
        weights = GetSingleParamWeight(training_data, param)
        all_weights.append(weights)
    return all_weights


def GetSingleParamWeight(training_data, param):
    x = training_data["x"]
    y = training_data["y"]
    x_t = x.transpose()
    return np.dot(np.dot(np.linalg.inv(np.dot(x_t, x) + param * np.identity(x.shape[1])), x_t), y)


def GetMSEs(data, file):
    all_errors = []
    weights = data[file]["weights"]
    x = data[file]["x"]
    y = data[file]["y"]
    for i in range(0, len(weights)):
        error = 0
        # calculates MSE for one param
        for j in range(0, x.shape[0]):
            error += (np.dot(weights[i], x[j]) - y[j])**2
        error /= x.shape[0]
        all_errors.append(error)
    return all_errors


def EvalMSEs(data, test_data, file_map):
    performances = {}
    for file in data:
        all_errors = []
        weights = data[file]["weights"]
        for i in range(0, len(weights)):
            all_errors.append(GetSingleMSE(weights[i], test_data[file_map[file]]))
        performances[file] = all_errors
    return performances


def GetSingleMSE(weights, test_data):
    error = 0
    x = test_data["x"]
    y = test_data["y"]
    for j in range(0, x.shape[0]):
        error += (np.dot(weights, x[j]) - y[j]) ** 2
    error /= x.shape[0]
    return error


def MakeTrainingTestMap():
    training_test_map = {}
    training_test_map.update({"train-100(1000)-100.csv": "test-1000-100.csv"})
    training_test_map.update({"train-100-10.csv": "test-100-10.csv"})
    training_test_map.update({"train-100-100.csv": "test-100-100.csv"})
    training_test_map.update({"train-1000-100.csv": "test-1000-100.csv"})
    training_test_map.update({"train-150(1000)-100.csv": "test-1000-100.csv"})
    training_test_map.update({"train-50(1000)-100.csv": "test-1000-100.csv"})
    return training_test_map


def CombineMSEs(training_data, performances):
    all_mse_data = {}
    for file in training_data:
        file_mses = {}
        training_mses = training_data[file]["errors"]
        test_mses = performances[file]
        file_mses["training"] = training_mses
        file_mses["test"] = test_mses
        all_mse_data[file] = file_mses
    return all_mse_data


def ShowTrainingResults(all_mse_data, performances):
    PrintLines()
    print("Plotting all values of lambda from 0 to 150 (maximize window for better clarity): ")
    PlotMSEs(all_mse_data, 0, 150)
    PrintLines()
    print("2a. Determining the minimum value of lambda for each test set:")
    PrintLines()
    PrintBestLambdas(performances)
    PrintLines()
    print("2b. Plotting all values of lambda from 1 to 150 (maximize window for better clarity): ")
    PlotMSEs(all_mse_data, 1, 150)
    PrintLines()


def PlotMSEs(all_mses, start, end):
    params = [x for x in range(start, (end+1))]
    for file in all_mses:
        plt.plot(params, all_mses[file]["training"][start:end+1], label=(file + " training"))
        plt.plot(params, all_mses[file]["test"][start:end+1], label=(file + " test"))
    plt.ylim(0, 20)
    plt.legend()
    plt.show()


def PrintBestLambdas(performances):
    for file in performances:
        PrintLines()
        print("File:", file)
        print("Best Param:", performances[file].index(min(performances[file])))
        print("MSE:", min(performances[file]))
        PrintLines()


def TrimRows(all_data, fold):
    partition = {"x": all_data["x"][:], "y": all_data["y"][:]}
    min_val = int(fold * (all_data["x"].shape[0]) / 10)
    max_val = int((fold + 1) * (all_data["x"].shape[0]) / 10 - 1)
    for i in range(min_val, max_val+1):
        partition["x"] = np.delete(partition["x"], i, 0)
        partition["y"] = np.delete(partition["y"], i, 0)
    return partition


def CrossValidate(all_data, num_folds, num_params, test_data, file_map):
    best_params = {}
    for file in all_data.keys():
        print("File:", file)
        average_errors = []
        training_data = []
        for fold in range(0, num_folds-1):
            training_data.append(TrimRows(all_data[file], fold))
        partition = {}
        max_val = int(num_folds * (all_data[file]["x"].shape[0]) / 10 - 1)
        partition["x"] = all_data[file]["x"][0:max_val]
        partition["y"] = all_data[file]["y"][0:max_val]
        training_data.append(partition)
        for i in range(0, num_params):
            total_error = 0
            for j in range(0, len(training_data)):
                weights = GetSingleParamWeight(training_data[j], i)
                total_error += GetSingleMSE(weights, test_data[file_map[file]])
            average_errors.append(total_error / num_params)
        best_params.update({file: average_errors.index(min(average_errors))})
    return best_params


def main():
    training_folder = GetFolder("Training")
    test_folder = GetFolder("Test")
    training_test_map = MakeTrainingTestMap()

    # initialize data
    PrintLines()
    print("Initializing Training Data:")
    PrintLines()
    training_data = SetTrainingData(training_folder)
    test_data = {}
    PrintLines()
    print("Initializing Test Data:")
    PrintLines()
    for file in os.listdir(test_folder):
        test_data[file] = GetDataFromFolder(test_folder, file)

    # evaluate and combine MSEs
    performances = EvalMSEs(training_data, test_data, training_test_map)
    all_mse_data = CombineMSEs(training_data, performances)
    ShowTrainingResults(all_mse_data, performances)                         # print outputs for no CV training!

    # idea for #3: reuse training functions, just add functionality to chop up datasets into groups of 10
    # merge groups as needed for training
    PrintLines()
    print("3. Cross Validating:")
    PrintLines()

    num_folds = 10
    num_params = 151
    best_params = CrossValidate(training_data, num_folds, num_params, test_data, training_test_map)

    # Cross Validation done! Now we just have to train the given parameters on the entire training set
    # Then, we print the MSEs of that parameter on the training set and on the test set
    PrintLines()
    print("3a. Training and evaluating based on cross validation-selected parameter:")
    PrintLines()

    cv_weights = {}
    cv_performances = {}
    for file in best_params.keys():
        cv_weights[file] = GetSingleParamWeight(training_data[file], best_params[file])
        cv_performances[file] = GetSingleMSE(cv_weights[file], test_data[training_test_map[file]])
        PrintLines()
        print("File:", file)
        print("Best Param:", best_params[file])
        print("MSE:", cv_performances[file])
        PrintLines()


if __name__ == "__main__":
    main()
