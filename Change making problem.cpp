#include <iostream>
#include <climits>
using namespace std;

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

void printCoins(int *count, int n, int *coins, int d)
{
    cout << "We choose coins ";
    n--;
    for (int i = 0; i < d; i++)
    {
        int value = count[n - coins[i]] + 1;
        if (value == count[n])
        {
            n -= coins[i];
            cout << coins[i] << ", ";
            i--;
        }
    }
    return;
}

void minCoins(int value, int *coins, int d)
{
    int count[value];
    count[0] = 0;
    for (int i = 1; i < value; i++)
    {
        count[i] = INT_MAX;

        for (int j = 0; j < d; j++)
        {

            if (i < coins[j])
                break;

            count[i] = min(count[i], count[i - coins[j]]);
        }
        ++count[i];
    }
    if (count[value - 1] != INT_MAX)
    {
        cout << "Number of coins required: " << count[value - 1] << endl;
        printCoins(count, value, coins, d);
    }
    else
    {
        cout << "Cannot be solved";
    }
    return;
}

int main()
{
    int n;
    cout << "Enter number of denomination coins: ";
    cin >> n;
    int nCoins[n];
    cout << "Enter value of denomination coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nCoins[i];
    }
    int amount;
    cout << "Enter amount to find change of: ";
    cin >> amount;
    minCoins(amount + 1, nCoins, n);
    return 0;
}