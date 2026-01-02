#include <bits/stdc++.h>
using namespace std;

int count(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    return count(n-1)+count(n-2);
}
int main() {
    
    int n=5;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++ ){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[5] << " ";
    return 0;
}