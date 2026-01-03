#include <bits/stdc++.h>
using namespace std;
vector<int> buildLPS(string &pat)
{
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // fallback
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = buildLPS(pattern);
    vector<int> matches;

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            matches.push_back(i - j); // pattern found
            j = lps[j - 1];           // continue searching
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return matches;
}

int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> result = KMPSearch(text, pattern);

    for (int idx : result)
        cout << "Pattern found at index " << idx << endl;

    return 0;
}
