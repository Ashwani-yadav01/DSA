#include <bits/stdc++.h>
using namespace std;



bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }

// 1653 saved in leetcode

// 506 saved in leetcode

// 1854 saved in leetcode

//1422 saved in leetcode

//2670 saved in leetcode

//2299 saved in leetcode

//completed 200
    int main() {
    
    // your code here
    
    return 0;
}
    