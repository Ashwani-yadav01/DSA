#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];  // complement

        // check if complement already seen
        if (mp.find(need) != mp.end()) {
            return {mp[need], i};  // return indices
        }

        // store current value with its index
        mp[nums[i]] = i;
    }

    return {}; // if no solution found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    if (!ans.empty())
        cout << "Indices: [" << ans[0] << ", " << ans[1] << "]\n";
    else
        cout << "No solution found\n";

    return 0;
}
