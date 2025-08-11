#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > n / 2)
        {
            return nums[i];
        }
    }

    return -1;
}
int main()
{
    vector<int> num = {1, 2, 1, 1, 2};
    int ans = majorityElement(num);

    cout << ans;
    return 0;
}