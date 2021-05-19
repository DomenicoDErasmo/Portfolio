import skimage.io
import numpy as np
import copy
import matplotlib.pyplot as plt


def main():
    file = "image.png"
    img = LoadImage(file)
    k_vals = [2, 3, 6, 10, 15, 20, 25]
    centroids = InitCentroids(k_vals)
    clusters = {}
    sse = {}
    for k in k_vals:
        print("Performing K-means for k = " + str(k))
        centroids[k], clusters[k] = KMeans(img, centroids[k])
        sse[k] = GetSSE(centroids[k], clusters[k])
        cluster_image = MakeClusterImageWithoutMapping(img, centroids[k], clusters[k])
        # cluster_image = MakeClusterImage(img, clusters[k])
        skimage.io.imshow(cluster_image)
        plt.savefig("Pictures/" + "k_" + str(k))
        plt.show()
    print(sse)


def LoadImage(file):
    img = skimage.io.imread(file)
    img = np.divide(img, 255)
    skimage.io.imshow(img)
    plt.show()
    return img


def InitCentroids(k_vals):
    centroids = {}
    fraction = 1/max(k_vals)
    for k in k_vals:
        centroids[k] = np.array([[fraction * i, fraction * i, fraction * i] for i in range(k)])
    print(centroids)
    return centroids


def KMeans(img,
           centroids):
    clusters = {k: [] for k in range(len(centroids))}
    for i in range(50):
        current_centroids = copy.deepcopy(centroids)
        clusters = BuildClusters(img, centroids)
        centroids = UpdateCentroids(centroids, clusters)
        if HasConverged(centroids, current_centroids):
            return centroids, clusters
    return centroids, clusters


def BuildClusters(img, centroids):
    clusters = {k: [] for k in range(len(centroids))}
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            distances = [np.linalg.norm(img[i][j] - centroids[k]) for k in range(len(centroids))]  # build all distances
            min_index = distances.index(min(distances))
            clusters[min_index].append(img[i][j])
    return clusters


def UpdateCentroids(centroids, clusters):
    for i in range(len(centroids)):
        centroids[i] = GetAverage(clusters[i])
    return centroids


def HasConverged(centroids, current_centroids):
    change = 0
    for i in range(len(centroids)):
        change += np.linalg.norm(centroids[i] - current_centroids[i])
    change /= len(centroids)
    print(change)
    return change < 0.05
    # return change < 0.001


def GetAverage(cluster):
    centroid = np.ndarray((3,))
    for i in range(len(centroid)):
        total = 0
        for x in cluster:
            total += x[i]
        centroid[i] = total/len(cluster)
    return centroid


def GetSSE(centroids, clusters):
    """
    Computes the SSEs for the provided clustering
    :param centroids: A 2D ndarray
    :param clusters: A dictionary of lists of 1x3 ndarrays
    :return: sse is a float
    """
    sse = 0
    for (i, centroid) in enumerate(centroids):
        for j, x in enumerate(clusters[0]):
            sse += np.linalg.norm(centroid - x) ** 2
    return sse


# Improvement: Speed this up, perhaps use references to original pixels instead of making a reverse map like Orian did?
def MakeClusterImage(img, clusters):
    print("Making Image")
    cluster_image = np.zeros(img.shape)
    reverse_cluster_map = {str(v): k for k, values in clusters.items() for v in values}
    color_list = [[60, 179, 113], [0, 191, 255], [255, 255, 0], [255, 0, 0], [0, 0, 0],
                  [169, 169, 169], [255, 140, 0], [128, 0, 128], [255, 192, 203], [255, 255, 255]]
    color_list = [[color_list[i][j]/255 for j in range(len(color_list[0]))] for i in range(len(color_list))]
    color_map = {i: color_list[i] for i in range(len(color_list))}
    reverse_cluster_map = {str(v): k for k, values in clusters.items() for v in values}
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            cluster_image[i][j] = color_map[reverse_cluster_map[str(img[i][j])]]
    return cluster_image


def MakeClusterImageWithoutMapping(img, centroids, clusters):
    print("Making image without arbitrary mapping:")
    cluster_image = np.zeros(img.shape)
    reverse_cluster_map = {str(v): k for k, values in clusters.items() for v in values}
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            cluster_image[i][j] = centroids[reverse_cluster_map[str(img[i][j])]]
    return cluster_image


if __name__ == "__main__":
    main()
