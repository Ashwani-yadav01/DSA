#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{   
    vector<int> nums = {-1, -2, -3, -4, -5};
    int curSum = 0;
    int maxSum = INT32_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        curSum += nums[i];
        maxSum = max(curSum, maxSum);
        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    cout << maxSum << endl;
    return 0;
}

// {
//     vector<int> nums = {1, 2, 3, 4, 5};
//     int max=INT32_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int currentSum = 0;
//         for (int j = i; j < nums.size(); j++)
//         {
//             currentSum += nums[j];
//             max = max > currentSum ? max : currentSum;
//         }
//     }
//     cout << max;
//     return 0;
// }