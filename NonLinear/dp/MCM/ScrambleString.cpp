#include <bits/stdc++.h>
using namespace std;
bool solve(string a, string b)
{

    if (a == b)
        return true;

    if (a.size() != b.size())
        return false;

    int n = a.size();
    if (n <= 1)
        return false;

    for (int i = 1; i < n; i++)
    {

        if (solve(a.substr(0, i), b.substr(n - i, i)) &&
            solve(a.substr(i, n - i), b.substr(0, n - i)))
            return true;

        if (solve(a.substr(0, i), b.substr(0, i)) &&
            solve(a.substr(i, n - i), b.substr(i, n - i)))
            return true;
    }
    return false;
}

bool isScramble(string s1, string s2)
{

    if (s1.size() != s2.size())
        return false;

    if (s1 == s2)
        return true;

    return solve(s1, s2);
}

int main()
{

    string s1 = "great";
    string s2 = "rgeat";
    cout << isScramble(s1, s2);

    return 0;
}