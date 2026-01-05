#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec={1,2,3,4};
  
    bool haveDuplicate=false;
    int size=vec.size();
    for (int i = 0; i < size-1; i++)
    {
       for (int j = i+1; j < size; j++)
       {
        if (vec[i]==vec[j])
        {
          haveDuplicate=true;
        }
       }
       
    }
    cout << haveDuplicate << endl;
    return 0;
}