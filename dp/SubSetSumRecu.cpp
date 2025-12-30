#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int target, int n)
{
    if (target == 0) return true;
    if (n == 0) return false;

    if (arr[n - 1] <= target)
    {
        return helper(arr, target - arr[n - 1], n - 1) ||
               helper(arr, target, n - 1);
    }
    return helper(arr, target, n - 1);
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 1234;
    int n = arr.size();

    cout << helper(arr, target, n);
    return 0;
}
