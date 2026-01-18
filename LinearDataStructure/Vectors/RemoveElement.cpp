#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }
    return k;
}
int main()
{
    vector<int> vec = {3,2,2,3};
    int val = 3;
    int ans = removeElement(vec, val);
    cout<< ans << endl;
    for (int i = 0; i < ans; ++i) {
    cout << vec[i] << " ";
}
    return 0;
}