#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x) {
    int st = 0, end = arr.size() - 1;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == x) {
            return arr[mid];
        }
        else if (arr[mid] < x) {
            ans = arr[mid];   // possible floor
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;
    int floorValue = findFloor(arr, x);
    if (floorValue != -1)
        cout << "Floor value of " << x << " is " << floorValue << endl;
    else
        cout << "No floor value found for " << x << endl;
    return 0;
}