#include <bits/stdc++.h>
using namespace std;

string lcsRecursive(string s1, string s2, int i, int j) {
    // Base case
    if (i == 0 || j == 0)
        return "";

    if (s1[i - 1] == s2[j - 1]) {
        return lcsRecursive(s1, s2, i - 1, j - 1) + s1[i - 1];
    }

    string op1 = lcsRecursive(s1, s2, i - 1, j);
    string op2 = lcsRecursive(s1, s2, i, j - 1);

    return (op1.size() > op2.size()) ? op1 : op2;
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << lcsRecursive(s1, s2, s1.size(), s2.size());
    return 0;
}
