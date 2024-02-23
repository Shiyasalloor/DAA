#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printLCS(const string& X, const string& Y, int** dp, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }

    if (X[i - 1] == Y[j - 1]) {
        printLCS(X, Y, dp, i - 1, j - 1);
        cout << X[i - 1];
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        printLCS(X, Y, dp, i - 1, j);
    } else {
        printLCS(X, Y, dp, i, j - 1);
    }
}

int longestCommonSubsequence(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();

    int** dp = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[m][n];

    cout << "Longest Common Subsequence: ";
    printLCS(X, Y, dp, m, n);
    cout << endl;

    for (int i = 0; i <= m; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    string X, Y;

    cout << "Enter the first sequence: ";
    cin >> X;

    cout << "Enter the second sequence: ";
    cin >> Y;

    int result = longestCommonSubsequence(X, Y);

    cout << "Length of the longest common subsequence: " << result << endl;

    return 0;
}
