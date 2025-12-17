#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // your code here
    vector<int> arr = {-1, -7, -3, -4};
    int n = arr.size();
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        if (currSum > maxSum) {
            maxSum = currSum;
        }
        if (currSum < 0) {
            currSum = 0;
        }
    }
    cout << "maxSum: " << maxSum;
    
    return 0;
}