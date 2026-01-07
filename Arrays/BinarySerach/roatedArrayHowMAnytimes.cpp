#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr) {
    int st = 0, end = arr.size() - 1;
    int N = arr.size();

    // already sorted (not rotated)
    if (arr[st] <= arr[end])
        return 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        int prev = (mid + N - 1) % N;
        int next = (mid + 1) % N;

        // pivot found
        if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
            return mid;
        }

        // left part sorted → go right
        if (arr[st] <= arr[mid]) {
            st = mid + 1;
        }
        // right part sorted → go left
        else if (arr[mid] <= arr[end]) {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << firstOcc(arr);
    return 0;
}
