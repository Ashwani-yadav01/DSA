#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s1=" AGGTAB";
    string s2="GXTXAYB";
    int n = s1.size();
    int m = s2.size();
    int dp[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j ==0 || i==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout << dp[n][m];
    
    return 0;
}