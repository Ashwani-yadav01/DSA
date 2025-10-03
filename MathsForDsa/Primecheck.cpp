#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter num  ";
    cin>> n;
   int count=0;
    for(int i=1;i*i<=n;i++){
        if(count>2) break;
        if(n%i==0){
            count++;
            if(n/i!=i){
                count++;
            }
        }
    }
    if(count==2){
        cout << "yes";
    }else{
        cout <<"no";
    }
    return 0;
}