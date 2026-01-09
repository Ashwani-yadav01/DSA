#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {2, 3, 1, 5, 6, 6};
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 != i)
        {
            cout << "Duplicate: " << arr[i]
                 << ", Missing: " << i + 1 << endl;
        }
    }
    // for (int val : arr)
    // {
    //     cout << val << " ";
    // }
    return 0;
}