#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int c1 = 0;
        int c2 = 0;
        int candidate1 = 0;
        int candidate2 = 1; // Initialize to two different values

        // Step 1: Find candidates
        for (int num : nums) {
            if (candidate1 == num) {
                c1++;
            } else if (candidate2 == num) {
                c2++;
            } else if (c1 == 0) {
                candidate1 = num;
                c1 = 1;
            } else if (c2 == 0) {
                candidate2 = num;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        // Step 2: Count occurrences
        c1 = 0;
        c2 = 0;
        for (int num : nums) {
            if (num == candidate1) c1++;
            else if (num == candidate2) c2++;
        }

        // Step 3: Check if counts exceed n / 3
        vector<int> ans;
        if (c1 > n / 3) ans.push_back(candidate1);
        if (c2 > n / 3) ans.push_back(candidate2);

        return ans;
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