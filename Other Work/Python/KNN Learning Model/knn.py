import numpy as np
import os
import math
from pathlib import Path
import scipy.stats as stats


def GetDistance(test_data, training_data):
    distance = 0
    for col in range(len(test_data)):
        distance += (test_data[col] - training_data[col])**2
    return math.sqrt(distance)


def FillDistanceMatrix(test_data, training_data):
    distances = np.zeros((test_data.shape[0], training_data.shape[0]))
    # get distances from each training data entry to each test data entry
    print("Getting distances")
    for row in range(0, test_data.shape[0]):
        if row % 100 == 0:
            print("Calculating distances for rows " + str(row) + "-" + str(row + 99))
        for col in range(0, training_data.shape[0]):
            distances[row][col] = GetDistance(test_data[row], training_data[col])

    return distances


def GetPredictions(distances, training_results, k_vals):
    all_predictions = {}
    for k in k_vals:
        predictions = []
        for row in range(0, distances.shape[0]):
            shortest_distances = np.argpartition(distances[row], k)[0:k]
            votes = sum([training_results[i] for i in shortest_distances])
            predictions.append(1) if votes > k / 2 else predictions.append(0)
        all_predictions[k] = predictions
    return all_predictions


def GetAccuracies(predictions, test_results, k_vals):
    accuracies = {}
    for k in k_vals:
        errors = 0
        for row in range(0, len(test_results)):
            if predictions[k][row] != test_results[row]:
                errors += 1
        accuracy = (len(test_results) - errors) / len(test_results)
        accuracies[k] = accuracy
    return accuracies


def KNN(normalization=False):
    directory = (Path(os.getcwd())).parent
    training_file = directory / "Resources" / "spam_train.csv"
    test_file = directory / "Resources" / "spam_test.csv"

    # loads all training data and test data into ndarrays
    all_training_data = np.genfromtxt(training_file, delimiter=',', skip_header=1)
    all_test_data = np.genfromtxt(test_file, delimiter=',', skip_header=1)

    # removes appropriate columns for training
    training_data = all_training_data[:, :-1]
    test_data = all_test_data[:, 1:-1]

    if normalization:
        for col in range(training_data.shape[1]):
            training_data[:, col] = stats.zscore(training_data[:, col])
        for col in range(test_data.shape[1]):
            test_data[:, col] = stats.zscore(test_data[:, col])

    # distances is a m x n matrix, where m = rows of test_data, and n = rows of training_data
    distances = FillDistanceMatrix(test_data, training_data)

    # gets the training and test labels
    training_results = all_training_data[:, -1]
    test_results = all_test_data[:, -1]

    # k values to test on
    k_vals = [1, 5, 11, 21, 41, 61, 81, 101, 201, 401]

    # forms a prediction based on the k closest labels
    predictions = GetPredictions(distances, training_results, k_vals)

    # measures accuracies
    accuracies = GetAccuracies(predictions, test_results, k_vals)
    for k in accuracies:
        print("k =", k, ", Accuracy =", accuracies[k])

    # print desired labels for 2c
    if normalization:
        label_meanings = {1: "spam", 0: "no"}
        for i in range(0, 50):
            print("t" + str(i+1), end=' ')
            for k in k_vals:
                print(label_meanings[predictions[k][i]], end=' ')
            print()


def main():
    KNN()                       # Part A: No data normalization
    KNN(normalization=True)     # Part B and C: With data normalization


if __name__ == "__main__":
    main()
