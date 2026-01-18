#include<iostream>
#include<algorithm>
using namespace std;
 char game(string str, char st, int k, string prev) {
    // base condition: if current string is long enough
    if (str.length() > k) {
        return str[k+1];
    }

    // generate the next version
    string curr = "";
    for (char c : prev) {
        curr += c;          // original
        curr += char(c + 1); // shifted
    }

    // if prev is empty (first step), start with "a"
    if (prev.empty()) curr = "a";

    cout << curr << endl;
    // recurse with new string as 'str'
    return game(curr, st, k, curr);
}
int main(){
   char ans=game("",'a',5,"");
   cout << ans;
    return 0;
}