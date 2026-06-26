#include <stdio.h>
int facto(int num)
{
    if (num)
    {
        return (num * (facto(num - 1)));
    }
    else
        return 1;
}

int main()
{
    int num;
    printf("enter a number: ");
    scanf("%d", &num);
    int fact = facto(num);
    printf("factorial of %d is %d", num, fact);
    return 0;
}