#include <stdio.h>
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
int main()
{
    int arr[20], n;
    printf("enter the size of the array: ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("Sorted array using bubblesorting algorithm: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// Algorithm BUBBLE_SORT(A, N):
// 1. For i = 0 to N-2:
// 2.   For j = 0 to N-i-2:
// 3.     If A[j] > A[j+1] Then Swap(A[j], A[j+1])