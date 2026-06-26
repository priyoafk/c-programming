#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 18, 23, 38, 45, 67, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);

    return 0;
}

// Algorithm BINARY_SEARCH(A, N, ITEM):
// 1. Set Low = 0, High = N-1
// 2. While Low <= High:
// 3.   Mid = (Low + High) / 2
// 4.   If A[Mid] == ITEM Then Return Mid
// 5.   Else If ITEM < A[Mid] Then High = Mid - 1
// 6.   Else Low = Mid + 1
// 7. Return -1