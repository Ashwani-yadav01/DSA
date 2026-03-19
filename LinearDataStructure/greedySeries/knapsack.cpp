#include <bits/stdc++.h>
using namespace std;

int main() {

    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int n = 3;
    int W = 50;

    vector<pair<double,int>> ratio;

    for(int i = 0; i < n; i++){
        ratio.push_back({(double)value[i] / weight[i], i});
    }

    sort(ratio.rbegin(), ratio.rend());

    double ans = 0;

    for(auto it : ratio){
        int idx = it.second;

        if(W >= weight[idx]){
            ans += value[idx];
            W -= weight[idx];
        }
        else{
            ans += value[idx] * ((double)W / weight[idx]);
            break;
        }
    }

    cout << ans;
}