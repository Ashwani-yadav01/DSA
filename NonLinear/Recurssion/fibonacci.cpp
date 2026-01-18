#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if (n == 1 || n == 0)
        return n;

    return fibo(n - 1) + fibo(n - 2);
}
int main()
{

    // your code here
    cout << fibo(7);
    return 0;
}