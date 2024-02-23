#include <iostream>
using namespace std;

int maxCoinRowValue(const int coins[], int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return coins[0];
    }

    int dp[n];
    
    dp[0] = coins[0];
    dp[1] = (coins[0] > coins[1]) ? coins[0] : coins[1];

    for (int i = 2; i < n; ++i) {
        dp[i] = (dp[i - 1] > (dp[i - 2] + coins[i])) ? dp[i - 1] : (dp[i - 2] + coins[i]);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout<<"Enter the number of coins : ";
    cin>>n;
    int coins[n];
    cout<<"Enter the value of coins : ";
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    cout<<"Maximum value in the Coin Row: " << maxCoinRowValue(coins, n)<<endl;

    return 0;
}
