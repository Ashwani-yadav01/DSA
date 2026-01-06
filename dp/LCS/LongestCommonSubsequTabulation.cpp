#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m];  // Output: 4
    return 0;
}
// for find the lenght of shortest common subsequence we have to use the formula
// Length of SCS = Length of s1 + Length of s2 - Length of LCS
// 1143
// 1092
// 583
// 712
// 1035
// 1458
// 97
// 115
// 72
// 392
// 516
// 1312
// 1682