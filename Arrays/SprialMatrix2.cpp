#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n)
{
    int srow = 0, scol = 0;
    int ecol = n - 1;
    int erow = n - 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<int> range;
    for (int i = 1; i <= n * n; i++)
    {
        range.push_back(i);
    }

    int k = 0;
    while (srow <= erow && scol <= ecol)
    {
        // top to right
        for (int j = scol; j <= ecol; j++)
        {
            ans[srow][j] = range[k++];
        }
        // right to bottom
        for (int i = srow + 1; i <= erow; i++)
        {
            ans[i][ecol] = range[k++];
        }
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
                break;
            ans[erow][j] = range[k++];
        }
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
                break;
            ans[i][scol] = range[k++];
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
    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
