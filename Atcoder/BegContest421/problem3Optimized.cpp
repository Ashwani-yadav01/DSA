#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    string S;

    cin >> N;
    cin >> S;

    vector<int> arr;
    long long count_even = 0;
    long long count_odd = 0;
    int a = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (S[i] == 'A')
        {
            int target_even = 2 * a;
            int target_odd = 2 * a + 1;
            count_even += abs(i - target_even);
            count_odd += abs(i - target_odd);
            a++;
        }
    }
    cout << min(count_even, count_odd);

    return 0;
}