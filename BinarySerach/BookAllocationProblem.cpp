#include <iostream>
#include <vector>
using namespace std;
bool isValid(int maxPagesAllowed, vector<int> &arr, int totalSt)
{
    int pages = 0;
    int st = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]>maxPagesAllowed) return false;
        if (pages + arr[i] <= maxPagesAllowed)
        {
            pages += arr[i];
        }
        else
        {
            st++;
            pages = arr[i];
        }
    }
    if (st <= totalSt)
        return true;

    return false;
}
int bookAllocation(vector<int> &arr, int s, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int start = 0;
    int end = sum;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(mid, arr, s))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> vec = {40,30,10,20};
    int s = 2;
    int n = vec.size();
    int ans = bookAllocation(vec, s, n);
    cout << ans << endl;
    return 0;
}