#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec={1,2,1,3,2,3,2,1};
    
    map<int,int> m;
    int c=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        m[vec[i]]++;
    }
    // your code here
     for (auto it : m) {
        cout << it.first << " -> " << it.second << endl;
    }
    return 0;
}