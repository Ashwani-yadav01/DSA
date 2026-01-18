#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<string> letters = {"a", "c", "f", "h"};
    string target = "f";
    int left = 0;
    int right = letters.size() - 1;
    string ans = "";
while(left <= right){
    int mid = left + (right - left) / 2;
    if(letters[mid] <= target){
        left = mid + 1;
    }
    else{
        ans = letters[mid];
        right = mid - 1;
    }
}
    if(ans == ""){
        ans = letters[0];
    }   
    cout << ans << " ";
    return 0;
}
