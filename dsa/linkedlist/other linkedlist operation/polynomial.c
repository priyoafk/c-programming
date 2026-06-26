#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coefficient;
    int exponent;
    struct node *link;
};

// Forward declaration
struct node *insert(struct node *head, float co, int ex);

struct node *create(struct node *head)
{
    int n, i, expo;
    float coefficient;

    printf("enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coefficient);
        printf("enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coefficient, expo);
    }
    return head; // Bug 1 fixed
}

struct node *insert(struct node *head, float co, int ex) // Bug 2 fixed
{
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->coefficient = co;
    newP->exponent = ex;
    newP->link = NULL;

    if (head == NULL || ex > head->exponent)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->exponent > ex)
        {
            temp = temp->link;
        }
        newP->link = temp->link; // Bug 4 fixed
        temp->link = newP;       // Bug 4 fixed
    }
    return head;
}

void print(struct node *head)
{
    if (head == NULL)
    {
        printf("No polynomial");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

int main()
{
    struct node *head = NULL;
    printf("enter the polynomial\n");
    head = create(head);
    print(head);
    return 0;
}