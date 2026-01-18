#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // your code here
    vector<int> jobs = {3, 2, 1, 4, 5};
    sort(jobs.begin(), jobs.end());
    for (int job : jobs) {
        cout << job << " ";
    }
    int t=0,wt=0;
    for(int i=0;i<jobs.size();i++){
        wt+=t;
        t+=jobs[i];
    }
    cout<<endl<<"Total waiting time: "<<wt;
    return 0;
}