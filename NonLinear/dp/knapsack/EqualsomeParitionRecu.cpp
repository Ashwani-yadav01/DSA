#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int target, int n)
{
    if (target == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] <= target)
    {
        return helper(arr, target - arr[n - 1], n - 1) ||
               helper(arr, target, n - 1);
    }
    return helper(arr, target, n - 1);
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    int target = 0;
    for (int val : arr)
        target += val;

    if (target % 2 == 1)
        return false;

    target = target / 2;
    int n = arr.size();

    cout << helper(arr, target, n);
    return 0;
}
