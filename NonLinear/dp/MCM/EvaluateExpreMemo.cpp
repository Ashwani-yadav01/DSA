#include <bits/stdc++.h>
using namespace std;

int dp[205][205][2];

int solve(string &s, int i, int j, bool isTrue) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        int lT = solve(s, i, k - 1, true);
        int lF = solve(s, i, k - 1, false);
        int rT = solve(s, k + 1, j, true);
        int rF = solve(s, k + 1, j, false);

        if (s[k] == '&') {
            if (isTrue)
                ans += lT * rT;
            else
                ans += lF * rT + lT * rF + lF * rF;
        }
        else if (s[k] == '|') {
            if (isTrue)
                ans += lT * rT + lT * rF + lF * rT;
            else
                ans += lF * rF;
        }
        else if (s[k] == '^') {
            if (isTrue)
                ans += lT * rF + lF * rT;
            else
                ans += lT * rT + lF * rF;
        }
    }

    return dp[i][j][isTrue] = ans;
}

int main() {
    string s = "T^F&T";
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, s.size() - 1, true);
    return 0;
}
