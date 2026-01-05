// generate boilerplate code for basic C++ program structure
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int> &arr)
{
    int pivot = -1;
    int n = arr.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i - 1] < arr[i])
        {
            pivot = i - 1;
            break;
        }
    }
    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    int i = pivot + 1, j = n - 1;
    while (i <= j)
    {
        swap(arr[i++], arr[j--]);
    }

   
}
int main()
{
    vector<int> nums = {1, 2, 5, 4, 3};
    nextPermutation(nums);
    return 0;
}