#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>> n;
    set<int> s;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            s.insert(i);
            if(n/i!=i){
                s.insert(n/i);
            }
        }
    }

    for(auto val: s){
        cout<< val << " ";
    }
    
    return 0;
}