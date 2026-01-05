#include <iostream>
#include <vector>
using namespace std;
vector<int> travse(vector<vector<int>> vec)
{
    int srow = 0, scol = 0;
    int ecol = vec[0].size() - 1;
    int erow = vec.size() - 1;
    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        // top to right
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(vec[srow][j]);
        }
        // right to bottom
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(vec[i][ecol]);
        }
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
                break;
            ans.push_back(vec[erow][j]);
        }
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
                break;
            ans.push_back(vec[i][scol]);
        }
        srow++;
        scol++;
        ecol--;
        erow--;
    }
    return ans;
}
int main()
{
    vector<vector<int>> vec = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    vector<int> ans = travse(vec);
    for (int v : ans)
    {
        cout << v << " ";
    }
    return 0;
}
