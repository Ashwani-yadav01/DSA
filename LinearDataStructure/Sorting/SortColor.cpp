#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int countOfZero = 0;
    int countOfOne = 0;
    int countOfTwo = 0;

    // Count occurrences of 0, 1, and 2
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) countOfZero++;
        else if (nums[i] == 1) countOfOne++;
        else if (nums[i] == 2) countOfTwo++;
    }

    // Overwrite the array with sorted values
    for (int i = 0; i < countOfZero; i++) {
        nums[i] = 0;
    }
    for (int i = countOfZero; i < countOfZero + countOfOne; i++) {
        nums[i] = 1;
    }
    for (int i = countOfZero + countOfOne; i < nums.size(); i++) {
        nums[i] = 2;
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    // Print the sorted array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}