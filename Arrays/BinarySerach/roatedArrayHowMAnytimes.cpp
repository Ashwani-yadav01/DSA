#include <iostream>
#include <vector>

using namespace std;

int findPivot(vector<int> &arr) {
    int st = 0, end = arr.size() - 1;
    int N = arr.size();

    // 1. Check if the array is not rotated at all
    

    while (st <= end) {
        if (arr[st] <= arr[end])
        return st;
        int mid = st + (end - st) / 2;
        
        // Circular index handling
        int prev = (mid + N - 1) % N;
        int next = (mid + 1) % N;

        // 2. Pivot found: The minimum element is smaller than both neighbors
        if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
            return mid;
        }

        // 3. Decide which side to search
        // If left part is sorted, pivot must be in the right part
        if (arr[st] <= arr[mid]) {
            st = mid + 1;
        } 
        // If right part is sorted, pivot must be in the left part
        else {
            end = mid - 1; // Corrected: use mid - 1 to avoid infinite loops
        }
    }
    return -1;
}

bool binarySearch(vector<int> &arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return true;
        
        if (target > arr[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main() {
    int target = 1;
    vector<int> arr = {2,4,5,6,7,0,1};

    int pivot = findPivot(arr);
    cout << "The array is rotated " << pivot << " times" << endl;

    bool found = false;

    // Search in the two sorted segments
    if (binarySearch(arr, 0, pivot - 1, target)) {
        found = true;
    } else if (binarySearch(arr, pivot, arr.size() - 1, target)) {
        found = true;
    }

    if (found) cout << "Target found" << endl;
    else cout << "Target not found" << endl;

    return 0;
}