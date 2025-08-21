#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 3, 1, 4, 5};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}