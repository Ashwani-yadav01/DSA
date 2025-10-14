#include <bits/stdc++.h>
using namespace std;
string decToBin(int n){
    string ans="";
    while(n>0){
        string rem=to_string(n%2);
        ans=rem+ans;
        n/=2;
    }
    return ans;
}
int main() {
    
    // your code here
    cout<< decToBin(12);
    return 0;
}