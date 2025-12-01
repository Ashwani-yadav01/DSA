#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n=5,m=5;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int n;
        cin>> n;
        if(n==1){
            cout << abs(2-i)+abs(2-j)<< endl;
            break;
        }
    }
    cout<< endl;
   }

    return 0;
}