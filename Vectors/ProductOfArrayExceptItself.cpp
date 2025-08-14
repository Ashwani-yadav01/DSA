#include <iostream>
#include <vector>
using namespace std;
vector<int> product(vector<int> &arr)
{
    int n= arr.size();
    vector<int> prefix;
    vector<int> suffix(n);
    vector<int> ans(n);
    prefix.push_back(1);
    suffix[n-1]=1;
    for (int i = 1; i < n; i++)
    {
        int val=arr[i-1]*prefix[i-1];
        prefix.insert(prefix.end(),val); 
    }
    for (int i = n-2; i >=0; i--)
    {
       suffix[i]=arr[i+1]*suffix[i+1];
    }
    for(int i=0; i<n; i++){
        ans[i]=prefix[i]*suffix[i];
    }
 return ans;   
}
int main()
{
    vector<int> vec = {1, 2, 3, 4};
    vector<int> ans = product(vec);
    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}