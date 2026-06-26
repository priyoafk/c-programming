#include <stdio.h>

int main()
{
    int arr[3][3], i, j, zero = 0, non_z = 0;
    int s[9][3], k = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("enter the element: ");
            scanf("%d", &arr[i][j]);
        }
    }
    printf("printing the array:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
                zero++;
            else
                non_z++;
        }
    }

    if (non_z > zero)
    {
        printf("this is not a sparse matrix\n");
    }
    else
    {
        for (j = 0; j < 3; j++)
        {
            for (i = 0; i < 3; i++)
            {
                if (arr[i][j] != 0)
                {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = arr[i][j];
                    k++;
                }
            }
        }
    // k acts as a row counter (or index) for the new matrix s
        printf("sparse matrix:\n");
        for (j = 0; j < non_z; j++)
        {
            for (i = 0; i < 3; i++)
            {
                printf("%d ", s[i][j]);
            }

            printf("\n");
        }
    }

    return 0;
}