#include <iostream>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int* weights, int* values, int n, int* selectedWeights) {
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[W + 1];
    }

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][W];

    int i = n, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedWeights[i - 1] = 1;
            w -= weights[i - 1];
        }
        --i;
    }

    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int* weights = new int[n];
    int* values = new int[n];
    int* selectedWeights = new int[n]{0}; 

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int result = knapsack(W, weights, values, n, selectedWeights);

    cout << "Maximum value that can be obtained: " << result << endl;

    cout << "Selected weights: ";
    for (int i = 0; i < n; ++i) {
        if (selectedWeights[i] == 1) {
            cout << weights[i] << " ";
        }
    }
    cout << endl;

    delete[] weights;
    delete[] values;
    delete[] selectedWeights;

    return 0;
}
