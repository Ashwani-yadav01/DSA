#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr)
{
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Initialization
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // DP computation
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= totalSum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] ||
                           dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Find minimum difference
    int minDiff = INT_MAX;
    for (int j = 0; j <= totalSum / 2; j++)
    {
        if (dp[n][j])
            minDiff = min(minDiff, totalSum - 2 * j);
    }

    return minDiff;
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    cout << minSubsetSumDifference(arr);
}
