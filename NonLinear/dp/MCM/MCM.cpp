#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <=j-1; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(temp, ans);
    }
    return ans;
}
int main()
{

  vector<int> arr={2,1,3,4};
  cout << solve(arr,1,arr.size()-1);

    return 0;
}

