#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> indexs;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }

    return {};
}
int main()
{
    vector<int> vec = {2, 7, 9, 11};
    int target = 9;
    vector<int> sol = twoSum(vec, target);
    for (int val : sol)
    {
        cout << val << " ";
    }
    return 0;
}
