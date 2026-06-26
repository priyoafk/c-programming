#include <stdio.h>

int main()
{
    int arr[30] = {10, 20, 30, 40, 60};
    int pos = 2, size = 5;
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("array after deletion: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}