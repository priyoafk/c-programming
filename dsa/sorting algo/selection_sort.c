#include <stdio.h>

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < (n - 1); i++) // to sorting the array
    {
        int min = i;
        for (int j = i + 1; j < n; j++) // for finding minimum
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[20], n;
    printf("enter the size of the array ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionsort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
    Algorithm SELECTION_SORT(A, N):
1. For i = 0 to N-2:
2.   Min_Idx = i
3.   For j = i+1 to N-1:
4.     If A[j] < A[Min_Idx] Then Min_Idx = j
5.   Swap(A[i], A[Min_Idx])
*/