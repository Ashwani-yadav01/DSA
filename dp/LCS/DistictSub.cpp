#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s ="babgbag";
    string t = "bag";
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // base case
    for (int j = 0; j <= n; j++)
        dp[0][j] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (t[i - 1] == s[j - 1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
              dp[i][j] = dp[i][j-1];
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << '\n';
    }
    // cout << dp[m][n];

    return 0;
}