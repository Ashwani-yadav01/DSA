#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 1, 3, 5};
    int b[] = {6, 7, 1, 3};
    int c[8];
    int k = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] == b[j]) {
                // Check if already added to c[]
                bool alreadyAdded = false;
                for (int m = 0; m < k; m++) {
                    if (c[m] == a[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    c[k] = a[i];
                    k++;
                }
            }
        }
    }

    cout << "Common elements count: " << k << endl;
    for (int i = 0; i < k; i++) {
        cout << c[i] << " ";
    }

    return 0;
}
