#include <stdio.h>
#define max 5
int stack[max];
int top = -1;
void push()
{
    if (top == max - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        int n;
        top++;
        printf("enter the element to push: ");
        scanf("%d", &n);
        stack[top] = n;
        printf("element has been stored\n");
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d is deleted\n", stack[top]);
        top--;
    }
}
void peek()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("top most element: %d\n", stack[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("stack elements: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf(" 1.push\n 2. pop\n 3.peek\n 4.display\n 5.exit\n");
        printf("enter a a case: ");
        scanf("%d", &choice);
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
            printf("program successfully terminated \n");
            break;
        default:
            printf("invalid choice\n");
            //  break;
        }
    } while (choice != 5);

    return 0;
}