#include <iostream>
#include <vector>
#include <string>
using namespace std;
void permutation(string &s, int idx)
{
    if (idx == s.length())
    {
        cout << s << " ";
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        swap(s[idx], s[i]);
        permutation(s,idx+1);
        swap(s[idx], s[i]);
    }
}
int main()
{
    string s = "abc";
    string ans;
    permutation(s, 0);
}