#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    string s="madam";
    cout<<isPalindrome(s);
    return 0;
}