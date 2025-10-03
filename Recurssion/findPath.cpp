#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis)
{
    if (r < 0 || c < 0 || r >= 4 || c >= 4 || mat[r][c] == 0 || vis[r][c] == true)
    {
        return;
    }

    if (r == 3 && c == 3)
    {
        ans.push_back(path);
    }

    vis[r][c] = true;
    helper(mat, r + 1, c, path + "D", ans, vis);
    helper(mat, r - 1, c, path + "U", ans, vis);
    helper(mat, r, c - 1, path + "L", ans, vis);
    helper(mat, r, c + 1, path + "R", ans, vis);
    vis[r][c] = false;
}
vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(4, vector<bool>(4, false));
    helper(mat, 0, 0, path, ans, vis);
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> path = findPath(arr);

    for (string s : path)
    {
        cout << s << endl;
    }
    return 0;
}