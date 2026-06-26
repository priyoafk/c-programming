#include <stdio.h>
#include <stdlib.h>
#define max 5
int top = -1;
int stack[max];
void push()
{
    int x;

    if (top == max - 1)
    {
        printf("stack overflow!!!\n");
    }

    else
    {
        printf("enter a value to store in the stack: ");
        scanf("%d", &x);
        top += 1;
        stack[top] = x;
        printf(" %d  has been stored in stack\n", x);
    }
    printf("\n");
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow!!!\n");
    }
    else
    {
        printf("%d is popped from the stack\n", stack[top]);
        top -= 1;
    }
    printf("\n");
}

void peak()
{
    if (top == -1)
    {
        printf("stack underflow!!!\n");
    }
    else
    {
        printf("top most element is %d\n", stack[top]);
    }
    printf("\n");
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("display stack's item\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int choice;

    do
    {
        printf(" 1.push\n 2. pop\n 3.peek\n 4.display\n 5.exit\n");
        printf("enter a a case: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("program successfully terminated ");
            break;
        default:
            printf("invalid choice\n");
            //  break;
        }
    } while (choice != 5);

    return 0;
}