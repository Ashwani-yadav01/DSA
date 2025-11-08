#include <stdio.h>

// Function to merge two halves
void merge(int arr[], int start, int mid, int end) {
    int i = start;       // starting index for left subarray
    int j = mid + 1;    // starting index for right subarray
    int k = 0;          // index for temp array
    int temp[end - start + 1];  // temporary array

    // Merge both halves into temp[]
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements of left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right half
    while (j <= end)
        temp[k++] = arr[j++];

    // Copy sorted elements back to original array
    for (i = start, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];
}

// Recursive merge sort function
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);       // sort left half
        mergeSort(arr, mid + 1, end);  // sort right half
        merge(arr, start, mid, end);    // merge the sorted halves
    }
}

int main() {
    int arr[] = {2, 3, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
