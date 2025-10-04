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
int print(int n)
{
    if (0 == n)
        return n;

    print(n - 1);
    cout << n << " ";
    return n;
}
// print n to 1 with backtrack
int print(int n, int i) {
    if (i > n) return i;  // stop when i exceeds n

    print(n, i + 1);      // go deep first
    cout << i << " ";     // print on the way back
    return n;
}
int main()
{

    //    print(1);
    // num(10,1);
    // print(10);
    print(10, 1);
    return 0;
}