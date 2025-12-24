#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int knapsack(int n, int W, vector<int> &weights, vector<int> &valarray)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (weights[n - 1] <= W)
    {
        return dp[n][W] = max(
            valarray[n - 1] + knapsack(n - 1, W - weights[n - 1], weights, valarray),
            knapsack(n - 1, W, weights, valarray)
        );
    }
    else
    {
        return dp[n][W] = knapsack(n - 1, W, weights, valarray);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));// Initialize dp array with -1

    int n = 4;
    vector<int> weights = {1, 3, 4, 5};
    vector<int> valarray = {1, 4, 5, 7};

    cout << knapsack(n, 7, weights, valarray);

    return 0;
}
