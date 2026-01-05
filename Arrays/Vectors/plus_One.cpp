#include<iostream>
#include <vector>
#include<math.h>
using namespace std; 
  vector<int> plusOne(vector<int>& digits) {
    int size= digits.size();
    for(int i=size-1; i>=0; i--){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        digits[i]=0;
    }
    digits.insert(digits.begin(),1);
    return digits;
    }
int main() {
    vector<int> digits={1,9,9};
    vector<int> result = plusOne(digits);
    for(int  val : result) {
        cout << val << " ";
    }
    
    return 0;
}