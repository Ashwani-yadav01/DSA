#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isSubsequence(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if(i==s.size()) return true;
    return false;
}
int main()
{
    string s = "node";
    string t = "neetcode";
    cout << isSubsequence(s, t);
    return 0;
}