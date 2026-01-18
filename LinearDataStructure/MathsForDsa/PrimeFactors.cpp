#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Handle negative numbers
    if (n < 0) {
        cout << "-1 ";
        n = -n;
    }

    cout << "Prime factors: ";

    // Step 1: Divide by 2 until odd
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Step 2: Check odd numbers from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Step 3: If n > 2, then n itself is prime
    if (n > 2)
        cout << n;

    return 0;
}
