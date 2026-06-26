#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addToEmpty(int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

struct node *addAtEnd(struct node *head, int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}
struct node *linkedlistTraverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct node *insert(struct node *head, int data)
{
    struct node *ptr;
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    int key = data;
    if (head == NULL || key < head->data)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        struct node *ptr = head;
        int key = newP->data;
        while (ptr->next != NULL && key > ptr->next->data)
        {
            ptr = ptr->next;
        }
        newP->next = ptr->next;
        ptr->next = newP;
    }
    return head;
}

int main()
{
    struct node* head = NULL;
    head = addToEmpty(12);
    addAtEnd(head,45);
    addAtEnd(head,19);
    addAtEnd(head,100);
    head  = insert(head,95);
    linkedlistTraverse(head);
    return 0;
}