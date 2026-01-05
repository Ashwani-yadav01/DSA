#include<iostream>
#include<vector>
using namespace std;
int removeDuplicate(vector<int>& arr){
int k=1;
int n=arr.size();
    for (int i = 1; i < n; i++)
    {
        if(arr[i]!=arr[i-1]){
            arr[k]=arr[i];
            k++;
        }
    }
return k;
}
int main(){
    vector<int> vec = {2,10,10,30,30,30};
    int ans=removeDuplicate(vec);
   for(int i = 0; i < ans; i++){
    cout<< vec[i] << " ";
   }
    return 0;
}