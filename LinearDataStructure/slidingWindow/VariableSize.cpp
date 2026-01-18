#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "aabacbebebe";
    int k = 3;
    int i = 0, j = 0;
    int ans = INT_MIN;
    unordered_map<char, int> m;

    while (j < s.size())
    {
        m[s[j]]++;
        if (m.size() < k)
        {
            j++;
        }
        else if (m.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {

            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout << ans;

    return 0;
}



// Given a string you need to print the size of the longest possible substring that has exactly k unique characters.


// Example:
// Input:
// 2
// aabacbebebe
// 3
// aaaa
// 1
// Output:
// 7
// 4 . 