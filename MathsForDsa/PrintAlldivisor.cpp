#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>> n;
    int ans=0;
    set<int> s;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            s.insert(i);
            ans+=i;
            if(n/i!=i){
                s.insert(n/i);
            ans+=n/i;
            }
        }
    }

    for(auto val: s){
        cout<< val << " ";
    }
    cout<< ans;
    return 0;
}