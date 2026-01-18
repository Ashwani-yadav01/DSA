#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {5, 6, 7};
    sort(arr.begin(), arr.end());

    int k = 10;
    int n = arr.size();
    int i = 0, j = n - 1;
    int x = -1, y = -1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum >= k)
        {
            j--;
        }
        else if (sum < k)
        {
            if (sum > x + y)
            {
                x = arr[i];
                y = arr[j];
            }
            else if (sum == x + y)
            {
                if (abs(arr[i] - arr[j]) > abs(x - y))
                {
                    x = arr[i];
                    y = arr[j];
                }
            }
            i++;
        }
    }
    cout << x << " " << y;
    return 0;
}