#include <bits/stdc++.h>
using namespace std;

int main()
{

    // your code here
    vector<int> arr = { 1,2,3,1};
    int n = arr.size();
    int target = 0;
    for(int i=0;i<n;i++){
        target+=arr[i];
    }
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    

    vector<int> vec;
    for(int i=0;i<=target/2;i++){
        if(dp[n][i]==1){
            vec.push_back(i);
        }
    }
     for(int i=0;i<vec.size();i++){
       cout << vec[i]<<" ";
    }
    cout << endl;
    int ans=INT_MAX;
    for(int i=0;i<vec.size();i++){
        ans=min(ans,target-2*vec[i]);
    }
    cout<<ans;
    return 0;
}