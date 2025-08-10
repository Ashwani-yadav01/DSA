#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int candidate;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {

            candidate = nums[i];
            cout << "candidate = " << candidate << endl;
            count++;
        }

        else if (nums[i] == candidate)
        {
            count++;
        }

        else
        {
            count--;
        }
    }

    return candidate;
}
int main()
{
    vector<int> num = {3, 2, 3};
    int ans = majorityElement(num);

    cout << ans;
    return 0;
}