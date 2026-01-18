#include<iostream>
using namespace std;
int main() {
    int r;
   int decNum=5;
   int ans=0;
   int pow=1;
   while (decNum>0) {
    r=decNum%2;
    decNum=decNum/2;
    ans+=(r*pow);
    pow*=10;
   }
    cout << ans << endl;
    return 0;
}