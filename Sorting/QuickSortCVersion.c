#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int start, int end)
{
    int idx = start - 1;
    int pivot = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(&arr[j], &arr[idx]);
        }
    }
    idx++;
    swap(&arr[end], &arr[idx]);
    return idx;
}

// QuickSort function
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivIdx = partition(arr, start, end);
        quickSort(arr, start, pivIdx - 1); // left half
        quickSort(arr, pivIdx + 1, end);   // right half
    }
}

int main()
{
    int arr[] = {2, 3, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
