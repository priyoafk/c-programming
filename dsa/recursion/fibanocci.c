#include <stdio.h>
int fib(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return fib(num - 1) + fib(num - 2);
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int fibo = fib(num);
    printf("fibbonnaci of series: %d", fibo);
    return 0;
}