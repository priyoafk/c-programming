#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
void push()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter a data: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("stack underflow");
    }
    else
    {
        printf(" %d element has  deleted", temp->data);
        top = top->next;
        free(temp);
    }
}
void peek()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("stack underflow");
    }
    else
    {
        printf("stack's top most element: %d", top->data);
    }
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("stack underflow");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
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
            printf("program successfully terminated ");
            break;
        default:
            printf("invalid choice\n");
            //  break;
        }
    } while (choice != 5);

    return 0;
}