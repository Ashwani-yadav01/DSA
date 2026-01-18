#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {-1, 20, -3, -4};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            maxSum = max(maxSum, curr);
            cout << maxSum << " ";
        }
    }
    cout << "maxSum" << maxSum;
    return 0;
}