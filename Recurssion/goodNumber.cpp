#include<iostream>
#include<algorithm>
using namespace std;

void goodNumber(int n){
int even=(n+1)/2;
int odd=n/2;
cout << even << " " << odd;
}
int main(){
    goodNumber(5);
    return 0;
}