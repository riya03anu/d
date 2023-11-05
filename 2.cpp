#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int maxWeight, int profit[], int weight[], int size) {
    int i, w;
    int K[size + 1][maxWeight + 1];

    // Initialize a 2D array to keep track of the selected items
    bool selected[size + 1][maxWeight + 1];

    for (i = 0; i <= size; i++) {
        for (w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
                selected[i][w] = false;
            } else if (weight[i - 1] <= w) {
                K[i][w] = max(profit[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
                if (profit[i - 1] + K[i - 1][w - weight[i - 1]] > K[i - 1][w]) {
                    selected[i][w] = true;
                } else {
                    selected[i][w] = false;
                }
            } else {
                K[i][w] = K[i - 1][w];
                selected[i][w] = false;
            }
        }
    }

    // Now, to get the items included, you can traverse the selected array
    int item = size;
    int remainingWeight = maxWeight;

    cout << "Max Profit: " << K[size][maxWeight] << endl;
    cout << "Items Included:" << endl;

    while (item > 0 && remainingWeight > 0) {
        if (selected[item][remainingWeight]) {
            cout << "Item " << item << " (Profit: " << profit[item - 1] << ", Weight: " << weight[item - 1] << ")" << endl;
            remainingWeight -= weight[item - 1];
        }
        item--;
    }
}

int main() {
    int size = 0;

    cout << "Enter No. of Items: ";
    cin >> size;

    int profit[size], weight[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << "th item profit Value: ";
        cin >> profit[i];

        cout << "Enter the " << i + 1 << "th item weight Value: ";
        cin >> weight[i];
    }

    int maxWeight = 0;

    cout << "Enter the max weight: ";
    cin >> maxWeight;

    knapsack(maxWeight, profit, weight, size);

    return 0;
}
