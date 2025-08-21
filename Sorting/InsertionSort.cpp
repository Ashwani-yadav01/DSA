#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 3, 1, 4, 5};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int minValue = INT_FAST32_MAX;
        int k = 0;
        for (int j = i; j < n; j++)
        {
            if (minValue > arr[j])
            {
                minValue = arr[j];
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}