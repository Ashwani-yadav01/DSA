#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    int count = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + start] = temp[idx];
    }

    return count;
}
int mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        int left = mergeSort(arr, start, mid);
        int right = mergeSort(arr, mid + 1, end);
        int invercount = merge(arr, start, mid, end);
         return left + right + invercount;
    }
    return 0;
}
int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};
    int count = mergeSort(arr, 0, arr.size() - 1);
    cout << count;
    return 0;
}