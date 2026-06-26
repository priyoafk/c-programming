#include <stdio.h>
#define max 5
int top = -1;
int stack[max];

void push()
{
    int x;
    if (top == max - 1)
    {
        printf("stack overflow");
    }
    else
    {
        printf("enter the value to push in stack ");
        scanf("%d", &x);
        top += 1;
        stack[top] = x;
        printf("%d has been stored in the stack", x);
    }
    printf("\n");
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        printf("%d has been popped from the stack ", stack[top]);
        top -= 1;
    }
    printf("\n");
}

void peek()
{
    if (top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        printf(" top element: %d ", stack[top]);
    }
    printf("\n");
}
void display()
{
    if (top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        printf("display stack's item\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int choice = 0;
    do
    {
        printf("1.push\n2.Pop\n3.peek\n4.display\n5.exit\n");
        printf("enter sl number to perform specific operation in stack ");
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
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("program terminated successfully\n");
            break;
        default:
            printf("invalid serial number to perform an operation");
            break;
        }
    } while (choice != 5);

    return 0;
}