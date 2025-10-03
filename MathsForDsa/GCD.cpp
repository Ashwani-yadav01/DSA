#include <iostream>
#include <vector>
using namespace std;
int GCD(int n1, int n2)
{
    if(n1==0) return n2;
    if(n2==0) return n1;
    if(n1%n2==0) return n2;
    if(n2%n1==0) return n1;

    int ans=1;
    for(int i=2;i<min(n1,n2);i++){
        if(n1%i==0&& n2%i==0){
            ans=i;
        }
    }
    return ans;
}
int main()
{
    int num1= 20;
    int num2 = 40;
    int ans= GCD(num1,num2) ;
    cout << ans<< endl;
    return 0;
}