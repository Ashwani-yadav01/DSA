#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void helper(vector<int> &arr, int i, vector<int> &com, vector<vector<int>> &ans, int target)
{
    int n=arr.size();
    if(i==n){
        return ;
    }
    if (target == 0)
    {
        ans.push_back(com);
        return;
    }
    if(target<0){
        return;
    }
    com.push_back(arr[i]);
    helper(arr, i + 1, com, ans, target - arr[i]);
    helper(arr, i, com, ans, target - arr[i]);
    com.pop_back();
    helper(arr, i + 1, com, ans, target);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> com;
    helper(arr,0,com,ans,target);
    return ans;
}
int main()
{
    vector<int> arr = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr, target);
    return 0;
}