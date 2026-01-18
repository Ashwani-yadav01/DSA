#include <iostream>
#include <vector>
using namespace std;
int GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if(a==0) return b;
    return a;
}
int main()
{
    int num1 = 11;
    int num2 = 11;
    int ans = GCD(num1, num2);
    cout << ans << endl;
    return 0;
}