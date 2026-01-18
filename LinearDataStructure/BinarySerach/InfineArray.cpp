#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170,180,190};
    int target = 10;
    int st=0,end=1;
    while(arr[end]<target){
        st=end;
        end=end*2;
    }
    cout << binarySearch(arr,target,st,end);
    //
    return 0;
}