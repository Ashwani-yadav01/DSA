#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    set<int> s(nums.begin(), nums.end());

    for(auto it: s){
        cout<< it<< " ";
    }
    auto it = s.rbegin();
    advance(it, k-1);

    return *it;
}
int main()
{
vector<int> arr={3,2,1,5,6,4};
int k=2;
    // your code here
cout << findKthLargest(arr,k);
    return 0;
}