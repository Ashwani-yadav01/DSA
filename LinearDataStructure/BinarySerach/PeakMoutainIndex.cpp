// generate the boilerplate code for a C++ program
#include <iostream>
#include <vector>
using namespace std;
int peakIndex(vector<int> &nums)
{
    int start = 1;
    int end = nums.size() - 2;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        if (nums[mid] < nums[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {0, 3, 8, 9, 5, 2};
    int ans = peakIndex(vec);
    cout << ans << endl;
    return 0;
}
