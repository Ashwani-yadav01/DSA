#include <bits/stdc++.h>
using namespace std;

long long rev(long long n)
{
    long long reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main()
{
    long long X, Y;
    cin >> X >> Y;

    long long prev2 = X;
    long long prev1 = Y;
    long long current = 0;

    for (int i = 2; i < 10; i++)
    {
        current = prev1 + prev2;
        current = rev(current);   // reversing a single digit doesn't change it

        prev2 = prev1;
        prev1 = current;
    }

    cout << current;

    return 0;
}