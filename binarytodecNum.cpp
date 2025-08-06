#include<iostream>
using namespace std;
int main() { 
int remainder;
int binary=11001;
int answer=0;
int pow=1;
while (binary>0){
    remainder=binary%10;
    binary=binary/10;
   answer+=(remainder*pow);
   pow*=2;
}
cout << answer<< endl;

    return 0;
}
