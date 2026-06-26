#include <stdio.h>
int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, num1 % num2);
    }
}

int main()
{
    int num1, num2;
    printf("enter the num1 and num2: ");
    scanf("%d %d", &num1, &num2);
    int result = gcd(num1, num2);
    printf("gcd of %d and %d : %d", num1, num2, result);
    return 0;
}