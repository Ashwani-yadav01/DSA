#include<iostream>
#include<vector>
using namespace std;
int main() {
    int  ans=0;
    vector<int> v={1,1,2,2,3};
    for(int val : v){
        ans= ans^ val;
    } 
    cout << ans << endl; // Output the single number
    return 0;
}
