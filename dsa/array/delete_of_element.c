#include <stdio.h>

int main()
{
    int arr[20] = {17, 19, 14, 10};
    int pos = 2, size = 4;
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}