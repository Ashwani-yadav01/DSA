#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> &num)
{
    int count = 1;
    int size = num.size();
    sort(num.begin(), num.end());
    for (int i = 1; i < size; i++)
    {
        if (num[i] == num[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count > size / 2)
        {
            return num[i];
        }
    }

    return num[0];
}

int main()
{
    vector<int> num = {3, 2, 3};
    int ans = majorityElement(num);

    cout << ans;
    return 0;
}