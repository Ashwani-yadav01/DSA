#include <bits/stdc++.h>
using namespace std;
// print name 5 times
// void print(int count){
//     if(count >5){
//         return;
//     }
//     cout<<"Ashwani";

// print(++count);
// }
//  print 1 to n
// void num(int n,int s){
// if(s>n){
//     return;
// }
// cout<< s<<" ";
// num(n,++s);
// }
// print n to 1

// void print(int n){
//     if(n<1){
//         return;
//     }
//     cout<< n << " ";
//     print(--n);
// }

// print 1 to n with backtrack
// int print(int n)
// {
//     if (0 == n)
//         return n;

//     print(n - 1);
//     cout << n << " ";
//     return n;
// }
// print n to 1 with backtrack
// int print(int n, int i)
// {
//     if (i > n)
//         return i;    // stop when i exceeds n
//     print(n, i + 1); // go deep first
//                      // print on the way back
//     return n;
// }
// int sumOfN(int n)
// {
//     if (n == 0)
//         return n;
//     return n + sumOfN(n - 1);
// }

// void severse(int i, vector<int> &v)
// {
//     if (i >= v.size() / 2)
//     {
//         return;
//     }
//     swap(v[i], v[v.size() - i - 1]);
//     severse(i + 1, v);
// }
bool palidrome(string &s, int i)
{
    if (i >= s.size() / 2)
    {
        return true;
    }

    if(s[i]!=s[s.size()-i-1]) return false;
    
    return palidrome(s,i+1);
}
int main()
{

    //    print(1);
    // num(10,1);
    // print(10);
    //    cout << sumOfN(3);

    // vector<int> vec = {1, 2, 3, 4, 5};
    // severse(0, vec);
    // for (int val : vec)
    // {
    //     cout << val << " ";
    // }
string s="madar";
int i=0;
    cout<< palidrome(s,i);
    return 0;
}