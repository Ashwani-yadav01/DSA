#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans=nums;
        int size= nums.size();
        for (int i = 0; i <size ; i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> result = getConcatenation(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}