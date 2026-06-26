#include <stdio.h>

int main()
{
    int arr[10] = {17, 16, 15, 14, 19};
    int pos = 4, value = 31, size = 5;
    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    size++;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}