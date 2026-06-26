#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *ptr) // points to the head node
{
    while (ptr != NULL)
    {
        printf("Elmenent: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *deleteatFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = p->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct node *deleteatlast(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node *DeleteByValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    struct node *sixth;
    struct node *seventh;
    // allocate memory for nodes in the nexted list in heap
    head = (struct node *)malloc(sizeof(struct node)); /* head is a struct pointer */
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));
    // nexted first & second nodes
    head->data = 7;
    head->next = second;
    // next secoond and third nodes
    second->data = 11;
    second->next = third;
    // terminate the list at the third node
    third->data = 24;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = fifth;

    fifth->data = 16;
    fifth->next = sixth;

    sixth->data = 19;
    sixth->next = seventh;

    seventh->data = 66;
    seventh->next = NULL;
    printf("traversing:\n");
    linkedlisttraversal(head);

    printf("node after deleting:\n");
    // head = deleteatFirst(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteatlast(head);
    head = DeleteByValue(head, 16);
    linkedlisttraversal(head);

    return 0;
}