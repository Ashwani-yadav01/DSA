#include <bits/stdc++.h>
using namespace std;

int searchNearlySorted(vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // check mid
        if (arr[mid] == target)
            return mid;

        // check mid-1
        if (mid - 1 >= st && arr[mid - 1] == target)
            return mid - 1;

        // check mid+1
        if (mid + 1 <= end && arr[mid + 1] == target)
            return mid + 1;

        // move search space
        if (target < arr[mid])
            end = mid - 2;
        else
            st = mid + 2;
    }
    return -1;
}
int main() {
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 40;
    int result = searchNearlySorted(arr, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}