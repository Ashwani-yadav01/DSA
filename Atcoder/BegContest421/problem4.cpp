#include <bits/stdc++.h>
using namespace std;

pair<int, int> finalPosition(int r, int c, string s)
{
    for (char ch : s)
    {
        if (ch == 'R')
            c++;
        else if (ch == 'L')
            c--;
        else if (ch == 'U')
            r--;
        else if (ch == 'D')
            r++;
    }
    return {r, c};
}

int main()
{
    int rt, ct, ra, ca, N, M, L;
    cin >> rt >> ct >> ra >> ca;
    cin >> N >> M >> L;

    vector<pair<string, int>> tdir;
    vector<pair<string, int>> Adir;

    for (int i = 0; i < M; i++)
    {
        int c;
        string s;
        cin >> s >> c;
        tdir.push_back({s, c});
    }

    for (int i = 0; i < L; i++)
    {
        int c;
        string s;
        cin >> s >> c;
        Adir.push_back({s, c});
    }

    int count = 0;
    int i = 0, j = 0;

    while (N-- > 0)
    {
       
    }

    cout << count;

    return 0;
}