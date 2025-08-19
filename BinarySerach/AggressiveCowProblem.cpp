#include <iostream>
#include <vector>
using namespace std;
int minLargestValue(vector<int> &arr, int cows)
{
    int start = INT32_MAX;
    int end = INT32_MIN;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        start = min(start, arr[i]);
        end = max(end, arr[i]);
    }
    cout << start << " " << end << endl;
    return 0;
}
int main()
{
    vector<int> positions = { 1, 2, 8, 4, 9};
    int cows = 3;
    int ans = minLargestValue(positions, cows);
    cout << ans << endl;
    return 0;
}