#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int maxArea(vector<int> &arr)
{
    int size = arr.size();
    int i = 0;
    int j = size - 1;
    int maxArea = 0;
    while (i < j)
    {
        int h = min(arr[i], arr[j]);
        int b = j - i;
        int area = h * b;
        maxArea = max(area, maxArea);
        if (arr[i] < arr[j])
            i++;
        else
            j--;
    }
    return maxArea;
}
int main()
{
    vector<int> vec = {1, 1};
    int ans = maxArea(vec);
    cout << ans << endl;
    return 0;
}
