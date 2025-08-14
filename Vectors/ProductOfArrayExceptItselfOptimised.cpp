#include <iostream>
#include <vector>
using namespace std;
vector<int> product(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
    {
        ans[i] = arr[i - 1] * ans[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= arr[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 3, 4};
    vector<int> ans = product(vec);
    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}