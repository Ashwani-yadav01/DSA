#include <iostream>
#include <vector>
using namespace std;
void insertionSort(int arr[])
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {2, 3, 1, 4, 5};
    insertionSort(arr);
    return 0;
}