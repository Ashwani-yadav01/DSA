#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 1;

    vector<int> vec;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            count++;
        }
        else
        {
            if (count > n / 3)
            {
                vec.push_back(nums[i - 1]);
            }
            count = 1;
        }
    }
    if (count > n / 3)
    {
        vec.push_back(nums[n - 1]);
    }
    return vec;
}
int main()
{
    vector<int> vec = {3, 2, 3};

    vector<int> ans = majorityElement(vec);
    for (int val : ans)
    {
        cout << val << endl;
    }
    return 0;
}