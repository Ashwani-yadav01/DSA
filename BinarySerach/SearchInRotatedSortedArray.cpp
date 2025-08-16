#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = 0;
    // if (n == 1 && arr[0] == target)
    //     return 0;
    // if (n == 1 && arr[0] != target)
    //     return -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[start] <= arr[mid])
        {
            if (arr[start] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && arr[end] >= target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {3,1};
    int target = 0;
    int ans = search(vec, target);
    cout << ans << endl;
    return 0;
}