#include <iostream>
#include <vector>
using namespace std;
int serach(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid == 0 && arr[0] != arr[1])
        {
            return arr[mid];
        }
        if (mid == n - 1 && arr[n - 1] != arr[n - 2])
            return arr[mid];
        if (arr[mid] != arr[mid - 1] && arr[mid + 1] != arr[mid])
        {
            return arr[mid];
        }
        if (mid % 2 == 0)
        {

            if (arr[mid] == arr[mid - 1])
            {
                end = mid - 1;
            }
            if (arr[mid] == arr[mid + 1])
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                start = mid + 1;
            }
            if (arr[mid] == arr[mid + 1])
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {0, 0, 1, 1, 2, 3, 3};
    int ans = serach(arr);
    cout << ans << endl;
    return 0;
}