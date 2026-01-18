#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &a, int target)
{
    int size = a.size();
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        if (a[i] + a[j] > target)
        {
            j--;
            cout << a[i] + a[j] << endl;
        }
        else if (a[i] + a[j] < target)
        {
            i++;
        }
        else
        {
            return {i, j};
            break;
        }
    }
    return {};
}

int main()
{
    vector<int> vec = {2, 3, 4, 5};
    int target = 9;
    vector<int> sol = twoSum(vec, target);
    for (int val : sol)
    {
        cout << val << " ";
    }
    return 0;
}