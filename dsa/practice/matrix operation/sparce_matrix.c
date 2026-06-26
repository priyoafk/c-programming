#include <stdio.h>

int main()
{
    int arr[3][3], i, j, zero = 0, non_z = 0;
    int s[3][9], k = 0;

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
    printf("\n");
    // checking the number of zero and non zero
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                zero++;
            }
            else
            {
                non_z++;
            }
        }
    }
    // printf("no of zero's: %d\n", zero);
    // printf("no of non zero element: %d\n", non_z);

    if (non_z > zero)
    {
        printf("this is not a sparse matrix");
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (arr[i][j] != 0)
                {
                    s[0][k] = i;
                    s[1][k] = j;
                    s[2][k] = arr[i][j];
                    k++;
                }
            }
        }

        printf("sparse matrix:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < non_z; j++)
            {
                printf("%d ", s[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}