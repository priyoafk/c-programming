#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertionAtBeginning(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return ptr;
}
struct node *insertionatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct node *insertafternode(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = prevnode->next;
    ptr->data = data;
    prevnode->next = ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 17;
    head->next = first;

    first->data = 18;
    first->next = second;

    second->data = 71;
    second->next = third;

    third->data = 19;
    third->next = NULL;
    traversal(head);

    // printf("insert at beginning:\n");
    // head = insertionAtBeginning(head, 81);
    // traversal(head);

    // printf("insert at Specific index\n");
    // head = insertionatindex(head, 56, 3);
    // traversal(head);

    // printf("insert at the end\n");
    // head = insertAtEnd(head, 64);
    // traversal(head);

    printf("insert after a node\n");
    head = insertafternode(head, second, 90);
    traversal(head);
    return 0;
}
/*
deleting element at the last index
struct node *p = head;
struct node *q = p -> next;
while(q -> next != NULL){
    q = q -> next;
}
while(p-> next != q -> data){
p = p -> next;
}
p -> next = NULL;
free(q);
*/