#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isFreqSame(vector<int> c1, vector<int> c2){
    for(int i=0; i<c1.size();i++){
        if(c1[i] !=c2[i]){
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    vector<int> count1(26, 0);
    for (int i = 0; i < s1.length(); i++)
    {
        count1[s1[i] - 'a']++;
    }

    int windSize = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0, idx = i;
        vector<int> windFreq(26, 0);
        while (windIdx < windSize && idx < s2.length())
        {
            windFreq[s2[idx] - 'a']++;
            idx++;
            windIdx++;
        }
        if(isFreqSame(count1,windFreq)){
            return true;
        }
    }

    return false;
}
int main()
{
    string s1 = "abx";
    string s2 = "eidbaooo";
   cout << checkInclusion(s1, s2);
    return 0;
}