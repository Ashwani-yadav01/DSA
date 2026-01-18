#include <iostream>
#include <vector>
using namespace std;
bool search(vector<vector<int>> vec, int target)
{
    int r = 0;
    int c = vec.size() - 1;
    while (r < vec.size() && c >= 0)
    {
        if (target == vec[r][c])
        {
            return true;
        }
        else if (target > vec[r][c])
        {
            r++;
        }
        else
        {
            c--;
        }
    }

    return false;
}
int main()
{
    vector<vector<int>> vec = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 13;
    cout << search(vec, target) << endl;
    return 0;
}
