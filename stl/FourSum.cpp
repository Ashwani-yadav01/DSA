#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &arr, int tar)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n;)
        {
            int p = j + 1, q = n - 1;
            while (p < q)
            {
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[p] + (long long)arr[q];
                if (sum < tar)
                {
                    p++;
                }
                else if (sum > tar)
                {
                    q--;
                }
                else
                {
                    ans.push_back({arr[i] , arr[j] , arr[p] , arr[q]});
                    p++, q--;
                    while (p < q && arr[p] == arr[p - 1])
                        p++;
                }
            }
            j++;
            if (j < n && arr[j] == arr[j - 1])
                j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    for (auto vec : res)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}