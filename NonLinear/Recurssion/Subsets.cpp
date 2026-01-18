#include <iostream>
#include <vector>
using namespace std;
 void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);
        ans.pop_back();
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(arr,ans,0,allSubsets);
for(auto i:allSubsets){
    for(auto j:i){
        cout<<j<<" ";
    }   
    cout<<endl;
}
    return 0;
}