#include <iostream>
using namespace std;
double power(double x, int n)
{
    if (n == 0)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;
    if (x == 1)
        return 1.0;
    if (x == 0)
        return 0.0;
    double result = 1;
    long binform = n;
    if (binform < 0)
    {
        x = 1 / x;
        binform = -binform;
    }
    while (binform > 0)
    {
        if (binform % 2 == 1)
            result *= x;

        x = x * x;
        binform = binform / 2;
    }
    return result;
}
int main()
{
    double ans = power(-1, -4);
    cout << ans << endl;
    return 0;
}