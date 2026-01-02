#include <bits/stdc++.h>
using namespace std;

int main()
{

    // your code here
    vector<int> arr = {1,2,5};
    int target = 11;
    int n = arr.size();
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i ][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout<< dp[n][target];

    return 0;
}