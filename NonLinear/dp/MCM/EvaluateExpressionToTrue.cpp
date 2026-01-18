#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int i, int j, bool isTrue) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        int lT = solve(s, i, k - 1, true);
        int lF = solve(s, i, k - 1, false);
        int rT = solve(s, k + 1, j, true);
        int rF = solve(s, k + 1, j, false);

        if (s[k] == '&') {
            if (isTrue) {
                ans += lT * rT;
            } else {
                ans += lF * rT + lT * rF + lF * rF;
            }
        }
        else if (s[k] == '|') {
            if (isTrue) {
                ans += lT * rT + lT * rF + lF * rT;
            } else {
                ans += lF * rF;
            }
        }
        else if (s[k] == '^') {
            if (isTrue) {
                ans += lT * rF + lF * rT;
            } else {
                ans += lT * rT + lF * rF;
            }
        }
    }

    return ans;
}

int main() {
    string expression = "T^F&T";
    cout << solve(expression, 0, expression.size() - 1, true);
    return 0;
}
