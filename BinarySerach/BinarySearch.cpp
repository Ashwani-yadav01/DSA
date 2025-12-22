#include <iostream>
#include <vector>
using namespace std;
bool serach(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, mid = 0;
    int end = n - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 6;
    bool isfound = serach(arr, target);
    cout << isfound << endl;
    return 0;
}