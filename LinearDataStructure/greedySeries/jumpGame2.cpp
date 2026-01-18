
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;      // number of jumps taken
        int end = 0;        // end of current jump range
        int farthest = 0;   // farthest index reachable in current range

        // We stop at nums.size() - 2 because when we reach the last index, no more jumps needed
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // when we reach the end of current range, we must jump
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << sol.jump(nums) << endl; // Output: 2
    return 0;
}
