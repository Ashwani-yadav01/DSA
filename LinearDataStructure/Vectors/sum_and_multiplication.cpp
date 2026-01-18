#include <iostream>
using namespace std;
int main()
{
    int arr[] = {7,6,5,4,3,2,1};
    int size = 7;
    int sum=0;
    int mul=1;
    for (int i = 0; i < size; i++)
    {
      sum+=arr[i]; 
        mul*=arr[i];
    }
    
    cout << "sum of array" << sum << endl;
    cout << "multi of array" << mul << endl;

     return 0;
}