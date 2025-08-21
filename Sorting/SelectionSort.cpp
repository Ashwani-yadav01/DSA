#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
    for (int val : arr)
    {
        cout << val << " ";
    }
}
int main()
{
    vector<int> arr = {2, 3, 1, 4, 5};
    insertionSort(arr);
    return 0;
}