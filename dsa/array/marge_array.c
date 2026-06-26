#include <stdio.h>

int main()
{
    int arr[] = {16, 1, 19, 16};
    int arr1[] = {15, 29, 19, 15};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr1) / sizeof(arr1[0]);
    int n3 = n1 + n2;
    int i, j;
    int merged[n3];
    for (i = 0; i < n1; i++)
    {
        merged[i] = arr[i];
    }
    for (j = 0; j < n2; j++)
    {
        merged[i + j] = arr1[j];
    }
    printf("merged of the array\n");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}
