#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 1, 2, 2, 3, 3, 4};
    int c[8];
    int k = 0;
    int s = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (a[i] == a[j])
            {
                s++;
            }
        }
        if (s == 1)
        {
            c[k] = a[i];
            k++;
        }
        s=0;
    }

    for (int i = 0; i < k; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}
