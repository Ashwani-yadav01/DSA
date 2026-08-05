#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    string A[100];
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int X;
    string Y;
    cin >> X >> Y;
    if(A[X-1] == Y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}