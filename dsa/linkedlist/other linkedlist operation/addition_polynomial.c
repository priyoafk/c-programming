#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coefficient;
    int exponent;
    struct node *link;
};


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
    return head;
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

void polyadd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->exponent > ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->link;
        }
        else if (ptr2->exponent > ptr1->exponent)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->link;
    }
    printf("Added ploynomial is \n");
    print(head3);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("enter the  first polynomial\n");
    head1 = create(head1);
    printf("enter the second polynomial\n");
    head2 = create(head2);

    polyadd(head1, head2);
    return 0;
}