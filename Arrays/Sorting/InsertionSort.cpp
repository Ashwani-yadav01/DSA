#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 3, 1, 4, 5};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}