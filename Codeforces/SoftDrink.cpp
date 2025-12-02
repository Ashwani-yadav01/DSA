#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int total_drink = k * l;
    int total_slices = c * d;
    int total_salt = p;

    int toasts_drink = total_drink / (n * nl);
    int toasts_limes = total_slices / n;
    int toasts_salt = total_salt / (n * np);

    cout << min({toasts_drink, toasts_limes, toasts_salt}) << endl;

    return 0;
}
