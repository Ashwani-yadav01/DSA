#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n, int currSum, int totalSum)
{
    // When all elements are considered
    if (n == 0)
    {
        int sum1 = currSum;
        int sum2 = totalSum - currSum;
        return abs(sum1 - sum2);
    }

    // Include current element
    int include = solve(arr, n - 1,
                        currSum + arr[n - 1], totalSum);

    // Exclude current element
    int exclude = solve(arr, n - 1,
                        currSum, totalSum);

    return min(include, exclude);
}

int main()
{
    vector<int> arr = {1,2,7};
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    cout << solve(arr, arr.size(), 0, totalSum);
}
