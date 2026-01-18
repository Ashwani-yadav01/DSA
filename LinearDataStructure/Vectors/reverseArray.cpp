#include <iostream>
using namespace std;
int main()
{
    int arr[] = {7,6,5,4,3,2,1};
    int size = 7;
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[size - i-1];
        // cout<< temp<< " ";
        arr[size - i-1] = arr[i];
        arr[i] = temp;
        
    }
    
     for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<< " ";
    }
     return 0;
}