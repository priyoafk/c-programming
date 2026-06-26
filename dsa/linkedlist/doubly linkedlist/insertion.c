#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void doubly_traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void doubly_traverse_reverse(struct node *ptr)
{

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    
}

struct node *doubly_Insertion_at_beginning(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    return ptr;
}
struct node *doubly_insertion_at_index(struct node *head, int index, int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    p->data = data;
    p->next = ptr->next;
    p->prev = ptr;
    if (ptr->next != NULL)
    {
        ptr->next->prev = p;
    }
    ptr->next = p;
    return head;
}
struct node *doubly_insertion_at_end(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    p->data = data;
    p->next = NULL;
    p->prev = ptr;
    ptr->next = p;
    return head;
}
struct node *doubly_insertion_after_a_node(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    ptr->prev = prevnode;
    if (prevnode->next != NULL)
    {
        prevnode->next->prev = ptr;
    }
    prevnode->next = ptr;
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));

    head->next = n2;
    head->data = 19;
    head->prev = NULL;

    n2->next = n3;
    n2->data = 10;
    n2->prev = head;

    n3->next = n4;
    n3->data = 17;
    n3->prev = n2;

    n4->next = NULL;
    n4->data = 14;
    n4->prev = n3;
    printf("Doubly Linked list after normal traversing:\n");
    doubly_traverse(head);
    printf("\n");

    // printf("Doubly Linked List after backward traversing\n");
    // // head =  doubly_traverse_reverse(ptr);
    // doubly_traverse_reverse(head);
    // printf("\n");

    // head = doubly_Insertion_at_beginning(head, 25);
    // printf("insertion at beginning\n");
    // doubly_traverse(head);
    // printf("\n");

    // head = doubly_insertion_at_index(head, 3, 15);
    // printf("insertion at index\n");
    // doubly_traverse(head);

    // printf("\n");

    // head = doubly_insertion_at_end(head, 22);
    // printf("Insertion at the end\n");
    // doubly_traverse(head);
    // printf("\n");

    head = doubly_insertion_after_a_node(head, n2, 36);
    printf("Insertion after a node\n");
    doubly_traverse(head);

    //  printf("\n reverse:\n");
    // doubly_traverse_reverse(head);
    // return 0;
}