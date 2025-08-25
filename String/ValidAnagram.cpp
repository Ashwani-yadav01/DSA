#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isAnagram(string s, string t)
{
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        count1[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        count2[t[i] - 'a']++;
    }

    for (int i = 0; i < count1.size(); i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s = "jar";
    string t = "raj";
    cout << isAnagram(s, t);
    return 0;
}