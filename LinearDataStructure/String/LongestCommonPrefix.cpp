#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &s)
{
    int n = s.size();
    string ans = "";
    int s1 = s[0].length();

    for (int j = 1; j < n; j++)
    {
        int idx = 0;
        int s2 = s[j].length();
        while (idx < s1 && idx < s2 && s[0][idx] == s[j][idx])
        {
            idx++;
        }
        s[0] = s[0].substr(0, idx);
        ans=s[0];
    }

    return ans;
}
int main()
{
    vector<string> strs = {"bat", "bag", "tank", "band"};
    cout << longestCommonPrefix(strs);
    return 0;
}