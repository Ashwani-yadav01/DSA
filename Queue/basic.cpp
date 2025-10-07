#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

void insert(int arr[], int &f, int &r, int item)
{
    if (r == SIZE - 1) // when rear reaches last index
    {
        cout << "overflow\n";
    }
    else if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        arr[r] = item;
    }
    else
    {
        r = r + 1;
        arr[r] = item;
    }
}

int main()
{
    int arr[SIZE];
    int f = -1, r = -1;
    int item = 1;

    for (int i = 0; i < 7; i++)
    {
        insert(arr, f, r, item);
        cout << "Rear = " << r << endl;
    }

    cout << "\nFinal Queue elements: ";
    for (int i = f; i <= r && i != -1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
