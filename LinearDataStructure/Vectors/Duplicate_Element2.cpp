#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> vec={1,2,2,3,4,5,6,7,8,9,10};
    sort(vec.begin(), vec.end()); // Ensure the vector is sorted
    bool haveDuplicate=false;
    int size=vec.size();
    for (int i =0; i < size; i++)
    {
        if (vec[i]==vec[i+1])
        {
        haveDuplicate=true;
        }
        
    }
    cout << haveDuplicate << endl;
    return 0;
}