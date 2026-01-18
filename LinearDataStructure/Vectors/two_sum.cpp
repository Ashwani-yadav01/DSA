#include<iostream>
#include <vector>
using namespace std;   
vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

int main(){
    vector<int> vec = {3,2,4};
    int target = 7;
    vector<int> sol = twoSum(vec, target);
    for (int val : sol) {
        cout << val << " ";
    }
    return 0;
}