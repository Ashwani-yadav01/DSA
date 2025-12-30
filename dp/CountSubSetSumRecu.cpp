#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr, int target, int n)
{
    if(target==0){
        return 1;
    }
    if(n==0) return 0;

    if (arr[n - 1] <= target)
    {
        return helper(arr, target - arr[n - 1], n - 1) +
               helper(arr, target, n - 1);
    }
    return helper(arr, target, n - 1);
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int target = 10;
    int n = arr.size();
    cout << helper(arr, target, n);
    return 0;
}
