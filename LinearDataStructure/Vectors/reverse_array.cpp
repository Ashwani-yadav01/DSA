#include <iostream>
#include <vector>
using namespace std;
vector<int> reverse(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[size- i - 1];
        arr[size - i - 1] = arr[i];
        arr[i] = temp;
    }
    return arr;
}
int main()
{

    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vector = reverse(vec);
    for (int val : vector)
    {
        cout << val << " ";
    }

    return 0;
}