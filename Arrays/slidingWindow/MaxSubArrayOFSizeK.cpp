#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    //
    int k = 2;
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MIN;
    int n = arr.size();
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = max(ans, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    cout << ans;
    return 0;
}