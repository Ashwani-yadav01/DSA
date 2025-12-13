#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> arr;

public:
    // Insert into heap
    void add(int data) {
        arr.push_back(data);
        int x = arr.size() - 1;

        while (x > 0) {
            int par = (x - 1) / 2;
            if (arr[x] < arr[par]) {
                swap(arr[x], arr[par]);
                x = par;
            } else break;
        }
    }

    // Get minimum element
    int peek() {
        if (arr.empty()) return -1;
        return arr[0];
    }

    // Heapify down
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int minIdx = i;

        if (left < arr.size() && arr[left] < arr[minIdx])
            minIdx = left;

        if (right < arr.size() && arr[right] < arr[minIdx])
            minIdx = right;

        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            heapify(minIdx);
        }
    }

    // Remove minimum
    int remove() {
        if (arr.empty()) return -1;

        int data = arr[0];
        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty())
            heapify(0);

        return data;
    }

    // Print heap array
    void print() {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    Heap h;

    // Adding values
    h.add(10);
    h.add(5);
    h.add(20);
    h.add(2);
    h.add(8);

    cout << "Heap array after insertions:\n";
    h.print();

    cout << "Min element (peek): " << h.peek() << endl;

    cout << "Removed: " << h.remove() << endl;
    cout << "Heap after removal:\n";
    h.print();

    cout << "Removed: " << h.remove() << endl;
    cout << "Heap after removal:\n";
    h.print();

    return 0;
}
