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
        // printf("%d",ptr->data);
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->prev;
    }
}
struct node *doubly_deletion_at_start(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}
struct node *doubly_deletion_at_index(struct node *head, int index)
{
    struct node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    struct node *deleting_node = ptr->next;
    ptr->next = deleting_node->next;
    if (deleting_node->next != NULL)
    {
        deleting_node->next->prev = ptr;
    }
    free(deleting_node);
    return head;
}
struct node *doubly_deletion_at_end(struct node *head)
{
    struct node *ptr = head->next;
    struct node *p = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    p->next = NULL;
    free(ptr);
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 13;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 17;
    third->next = fourth;

    fourth->data = 19;
    fourth->next = NULL;

    printf(" doubly linked list before deletion\n");
    doubly_traverse(head);
    printf("\n");

    // printf("doubly linked list after deletion at first\n");
    // head = doubly_deletion_at_start(head);
    // doubly_traverse(head);

    // printf("Doubly Linked list after deletion at Index\n");
    // head = doubly_deletion_at_index(head, 2);
    // doubly_traverse(head);
    printf("Doubly linked list after deletion at the end\n");
    head = doubly_deletion_at_end(head);
    doubly_traverse(head);
    return 0;
}