#include <stdio.h>

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i; // Return index if found
    }
    return -1; // Not found
}

int main()
{
    int arr[] = {64, 25, 12, 38, 45, 91, 7, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 38;

    int result = linearSearch(arr, size, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);

    return 0;
}

// Algorithm LINEAR_SEARCH(A, N, ITEM):
// 1. For i = 0 to N-1:
// 2.   If A[i] == ITEM Then Return i (Found)
// 3. Return -1 (Not Found)