#include <bits/stdc++.h>
using namespace std;

void solve(int i, int sum, int target, vector<int> &arr, vector<int> &subset)
{
    // if sum matches target
    if (sum == target)
    {
        for (int x : subset)
            cout << x << " ";
        cout << endl;
        return;
    }

    // if sum exceeds or index out of bounds
    if (i >= arr.size() || sum > target)
        return;

    // include current element
    subset.push_back(arr[i]);
    solve(i + 1, sum + arr[i], target, arr, subset);

    // exclude current element
    subset.pop_back();
    solve(i + 1, sum, target, arr, subset);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;

    vector<int> subset;
    solve(0, 0, target, arr, subset);

    return 0;
}