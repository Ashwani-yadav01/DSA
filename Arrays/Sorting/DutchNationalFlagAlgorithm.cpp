#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec={0,1,2,0,1,2};
    int mid=0;
    int low=0;
    int high=vec.size()-1;
    while (mid<=high)
    {
        if(vec[mid]==0){
            swap(vec[low],vec[mid]);
            low++;
            mid++;
        }
        else if(vec[mid]==1){
            mid++;
        }else{
            swap(vec[mid],vec[high]);
            high--;
        }
    }
    for(int val: vec){
        cout << val << " ";
    }
    return 0;
}