#include <iostream>
#include <vector>
using namespace std;
bool isValid(int maxTime, vector<int> &arr, int totalPainter, int size)
{
    int time = 0;
    int possiblePainter = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxTime)
        {
            return false;
        }
        if (time + arr[i] <= maxTime)
        {
            time += arr[i];
        }
        else
        {
            possiblePainter++;
            time = arr[i];
        }
    }
    return possiblePainter > totalPainter ? false : true;
}
int bookAllocation(vector<int> &arr, int s, int n)
{
    int totaltime = 0, maxValuue=INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        totaltime += arr[i];
        maxValuue=max(maxValuue, arr[i]);
    }
    int start = maxValuue;
    int end = totaltime;
    int mintime = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(mid, arr, s, n)){
            mintime=mid;
            end=end-1;
        }else{
            start=mid+1;
        }
    }
    return mintime;
}
int main()
{
    vector<int> vec = {40, 30, 10, 20};
    int s = 2;
    int size = vec.size();
    int ans = bookAllocation(vec, s, size);
    cout << ans << endl;
    return 0;
}