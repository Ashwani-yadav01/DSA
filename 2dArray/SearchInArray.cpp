#include <iostream>
#include <vector>
using namespace std;
bool search(vector<vector<int>> vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;
    while (start <= end)
    {
        int midR = start + (end - start) / 2;
        int l = vec[midR].size() - 1;
        if (vec[midR][0] <= target && vec[midR][l] >= target)
        {
            // second bin logic
            int s = 0;
            int e = l;
            while (s <= e)
            {
                int m = s + (e - s) / 2;
                if (vec[midR][m] == target)
                {
                    return true;
                }
                else if (vec[midR][m] < target)
                {
                    s = m + 1;
                }
                else
                {
                    e = m - 1;
                }
            }
            return false;
        }
        else if (target < vec[midR][0])
        {
            end = midR - 1;
        }
        else if (target > vec[midR][l])
        {
            start = midR + 1;
        }
    }

    return false;
}
int main()
{
    vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;
    cout << search(vec, target) << endl;
    return 0;
}
