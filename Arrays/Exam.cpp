#include <stdio.h>

// Function to insert element at a given position

int linearSerach(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return 1;
    }
    return 0;
}
void binSearch(int arr[], int data, int size)
{
    int start = 0, end = size - 1, mid = start + end / 2;
    while (arr[mid] != data && start < end)
    {
        if (arr[mid] < data)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + end / 2;
    }
    if (arr[mid] == data)
    {
        printf("item is found");
    }
    else
    {
        printf("ittem does no exist");
    }
}

int main()
{
    int arr[10] = {10, 30, 20, 4, 80, 70};
    int n = 6;
   // bubble sort
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n - i - 1; j++)
         {
             if (arr[j] > arr[j + 1])
             {
                 int temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
             }
         }
     }
    //selection sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n ; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // selection sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
