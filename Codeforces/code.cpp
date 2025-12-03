#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{

    vector<int> a = {6, 6, 12, 12};
    bool f = false;
    int ans = 2;
    while (!f)
    {
        for (int i = 0; i < a.size(); i++)
        {
            long long g = gcd(a[i], ans);
            cout << g;
            if (g == 1)
            {
               
                cout << ans << " ";
                return 0;
            }
        }
        if(!f) ans++;
    }

    cout << -1;
    return 0;
}
