#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int left, int right,int target){
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            ans=mid;
            right=mid-1;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}
int main() {
    
    vector<int> arr={0,0,0,0,0,1,1,1,1,1};
    int target=1;
    int st=0;
    int end=1;
    while(arr[end]==0){
        st=end;
        end=2*end;
    }
    cout << binarySearch(arr,st,end,target);
    return 0;
}
// 1 2 3 4 5 11 12 // minium diffrence
// key = 5 // 1.present next smaller and next greater 
// ans = next gearter - key=
// ans = key-nextsmaller =