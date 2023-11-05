#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

// Function to reduce rows and columns in the cost matrix
void reduceMatrix(vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();

    // Reduce rows
    for (int i = 0; i < n; i++) {
        int minVal = INF;
        for (int j = 0; j < n; j++) {
            if (costMatrix[i][j] < minVal) {
                minVal = costMatrix[i][j];
            }
        }
        if (minVal != INF) {
            for (int j = 0; j < n; j++) {
                if (costMatrix[i][j] != INF) {
                    costMatrix[i][j] -= minVal;
                }
            }
        }
    }

    // Reduce columns
    for (int j = 0; j < n; j++) {
        int minVal = INF;
        for (int i = 0; i < n; i++) {
            if (costMatrix[i][j] < minVal) {
                minVal = costMatrix[i][j];
            }
        }
        if (minVal != INF) {
            for (int i = 0; i < n; i++) {
                if (costMatrix[i][j] != INF) {
                    costMatrix[i][j] -= minVal;
                }
            }
        }
    }
}

// Branch and Bound function
void branchAndBoundTSP(vector<vector<int>>& costMatrix, int& minCost, int level, int pathLength, vector<int>& path, vector<int>& minPath) {
    int n = costMatrix.size();

    if (level == n) {
        // All cities have been visited
        pathLength += costMatrix[path[level - 1]][path[0]];
        if (pathLength < minCost) {
            minCost = pathLength;
            minPath = path;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (costMatrix[path[level - 1]][i] != INF) {
            if (find(path.begin(), path.end(), i) == path.end()) {
                int temp = costMatrix[path[level - 1]][i];
                pathLength += temp;

                if (pathLength + (n - level) * temp < minCost) {
                    path[level] = i;
                    branchAndBoundTSP(costMatrix, minCost, level + 1, pathLength, path, minPath);
                }

                pathLength -= temp;
            }
        }
    }
}

int main() {

    int n;  // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> costMatrix(n, vector<int>(n));

    cout << "Enter the cost matrix (use 0 for unconnected cities):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
            if (costMatrix[i][j] == 0) {
                costMatrix[i][j] = INF;
            }
        }
    }

    vector<int> path(n);
    vector<int> minPath(n);
    int minCost = INF;

    reduceMatrix(costMatrix);
    path[0] = 0;  // Starting from city 0
    branchAndBoundTSP(costMatrix, minCost, 1, 0, path, minPath);

    cout << "Optimal TSP tour: ";
    for (int i = 0; i < n; i++) {
        cout << minPath[i] << " -> ";
    }
    cout << minPath[0] << endl;

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
