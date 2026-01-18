#include <bits/stdc++.h>
using namespace std;
int searchCeilValue(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    int ceilIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return arr[mid];
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            ceilIndex = mid;
            right = mid - 1;
        }
    }

    return (ceilIndex != -1) ? arr[ceilIndex] : -1; // Return -1 if no ceil value found
}
int main() {
    
    vector<int> arr={2,1,3,4};

    
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10

// key 2 
