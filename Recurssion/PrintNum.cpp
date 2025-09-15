#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printNum(int a, int b)
{
    if (a > b)
    {

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

int sumA(vector<int> a)
{
    if (a.size() == 0)
    {
        return 0;
    }
    int b = a[0];
    a.erase(a.begin());
    return b + sumA(a);
}

string reverseString(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = reverseString(s.substr(1));
    return ans + ch;
}

int factorial(int n){
    if(n<0) return -1;
    if(n==0 || n==1) return 1;
    return n *factorial(n-1);
}
int main()
{
    string s = "abcd";
    // cout << reverseString(s);
    //  string s1 = "abcde";
    //  string s2 = "abcde";
    //  cout << s1+s2<< endl;
    
    cout<< factorial(-1)<< " ";
    return 0;
}