#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec={10,5,10,15,10,5,10,5,10,15,10,5};
    
    map<int,int> m;
    int n=vec.size();
    for(int i=0;i<n;i++){
        m[vec[i]]++;
    }
    int maxe=0;
    int mine;
    // your code here
     for (auto it : m) {
        maxe=max(it.second,maxe);
        mine=min(it.second,mine);
        cout << it.first << " -> " << it.second << endl;
    }
    cout << maxe <<" "<< mine;
    return 0;
}