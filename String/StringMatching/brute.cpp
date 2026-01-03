#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcdefgh";
    string pattern = "def";

    int n = s.size();
    int m = pattern.size();
    bool isFound = false;

    for (int i = 0; i <= n - m; i++) {
        int idx = 0;

        for (int j = i; j < i + m; j++) {
            if (s[j] == pattern[idx]) {
                idx++;
            } else {
                break;
            }
        }

        if (idx == m) {
            isFound = true;
            break;
        }
    }

    if (isFound) {
        cout << "Pattern Found" << endl;
    } else {
        cout << "Pattern Not Found" << endl;
    }

    return 0;
}
