#include <stdio.h>

int main()
{
    int b = 10;
    int a[] = {10, 20, 30, 40};
    int *p, *q, *r;
    p = &b;
    r = a;
    q = &a[2];
    // p = b;
    // printf("%d",*p);
    printf("%p\n", &b);
    printf("%p\n", p);
    printf("%p\n", a);
    printf("%p\n", q);
    q++; // it is allowed  becose it change other address than base address
    // a++; //it is not allowed
    printf("%p\n", &q);
    printf("%d\n", *(a + 2));
    return 0;
}