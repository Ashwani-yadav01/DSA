#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string compress(string s)
{
    int n = s.size();
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        int count = 0;
        while (i < n && ch == s[i])
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            s[idx++] = ch;
        }else{
            s[idx++]=ch;
            string ct=to_string(count);
            for(char dgt : ct){
                s[idx++]=dgt;
            }
        }
        i--;
    }
    s.resize(idx);
    return s;
}
int main()
{
    string s = "aabbbcccc";
    cout << compress(s);
    return 0;
}