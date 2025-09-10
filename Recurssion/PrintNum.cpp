#include <iostream>
#include <vector>
using namespace std;
void printNum(int a, int b)
{
    if (a == b)
    {
        cout << a << " ";
        return;
    }

    cout << a << " ";
    printNum(a + 1, b);
}
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

bool isSorted(vector<int> &vec, int n)
{
    if (n == 0 || n == 1)
        return true;

    return (vec[n - 1] >= vec[n - 2]) && isSorted(vec, n - 1);
}
int main()
{
    vector<int> vec = {1, 2, 6, 4, 5};
    int n = vec.size();

    cout << isSorted(vec, n);
    return 0;
}