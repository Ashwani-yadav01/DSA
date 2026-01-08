#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int dp[2001][2001];

int solve(string &s, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPalindrome(s, i, j))
        return dp[i][j] = 0;

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int left, right;

        if (dp[i][k] != -1)
            left = dp[i][k];
        else
            left = dp[i][k] = solve(s, i, k);

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = dp[k + 1][j] = solve(s, k + 1, j);

        ans = min(ans, left + right + 1);
    }

    return dp[i][j] = ans;
}

int minCut(string s)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, s.size() - 1);
}
int main()
{

    string s = "nitin";
    cout << minCut(s);

    return 0;
}