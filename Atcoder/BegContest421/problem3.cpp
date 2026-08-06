#include <bits/stdc++.h>
using namespace std;

int findFirstElement(vector<int> &arr, int start, int target)
{
    for (int i = start; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int solve(vector<int> arr, int start)
{
    int swaps = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int need = (i % 2 == 0) ? start : 1 - start;

        if (arr[i] == need)
            continue;

        int j = findFirstElement(arr, i + 1, need);

        if (j == -1)
            return INT_MAX;

        swaps += (j - i);

        while (j > i)
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    return swaps;
}
int main()
{
    int N;
    string S;

    cin >> N;
    cin >> S;

    vector<int> arr;

    for (char c : S)
        arr.push_back(c == 'A' ? 0 : 1);

    int ans = min(solve(arr, 0), solve(arr, 1));

    cout << ans << endl;

    return 0;
}