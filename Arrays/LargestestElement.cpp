#include <bits/stdc++.h>
using namespace std;

int main()
{

    // your code here
    vector<int> arr = {2, 1, 3, 5, 4};
    int ans = INT32_MIN;
    int secondLar=INT32_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        ans=max(arr[i],ans);
        if(arr[i]<ans){
            secondLar=max(arr[i],secondLar);
        }
    }
    cout << ans << " " << secondLar;
    return 0;
}