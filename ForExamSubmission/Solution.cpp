#include <bits/stdc++.h>
using namespace std;

// valid parentheses(leetcode 20)


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


//stock span(leetcode 901) this saved in leetcode

// 1653 saved in leetcode

// 506 saved in leetcode



    int main() {
    
    // your code here
    
    return 0;
}
    