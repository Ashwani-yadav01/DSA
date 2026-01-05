#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    vector<int> vec;
    vec={1,2,3};
    vec.push_back(1);
    cout << "size =" << vec.size()<< endl;
    for(int i : vec){
        cout << i << " ";
    }
    return 0;
}