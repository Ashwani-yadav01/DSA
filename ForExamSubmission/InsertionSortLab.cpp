#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int n = arr.size();
    for (int i =0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    for(int value : arr){
        cout << value << " ";
    }
    return 0;
}