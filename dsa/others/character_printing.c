#include <stdio.h>

int main()
{
    int n;
    printf("enter the value: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        int a = 1;
        for (int j = 0; j <= i; j++)
        {
            int d = a + 64;
            char ch = (char)d;
            printf("%c ", ch);
            a++;
        }
        printf("\n");
    }

    return 0;
}