#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "pwwkew";

    unordered_map<char, int> m;
    int i = 0, j = 0;
    int ans = INT_MIN;
    while (j < s.size())
    {
        m[s[j]]++;
        if (m.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
        }
        if(m.size()<j-i+1)
        {
            while (m.size() < j - i + 1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    cout << ans;
    return 0;
}


// Given a string s, find the length of the longest substring without repeating characters.


// Example:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring