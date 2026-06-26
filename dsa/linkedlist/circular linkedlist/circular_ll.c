#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertion_at_beginning(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    do
    {
        p = p->next;
    } while (p->next != head);
    //at this point p is pointing to the last node which is now pointing p's next == head in this circular llnked list
    p->next = ptr;
    ptr->next = head;

    head = ptr;
    return head;
}

struct node *insertion_at_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertion_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct node *insertion_by_value(struct node *head, int data, struct node *prev)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = prev;
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *deletion_at_first(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr->next;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deletion_at_index(struct node *head, int index)
{
    struct node *ptr = head->next;
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct node *deletion_at_end(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = head;
    free(p);
    return head;
}
struct node *deletion_by_value(struct node *head, struct node *prev)
{
    struct node *ptr = prev;
    struct node *p = ptr->next;

    ptr->next = p->next;
    free(p);
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 17;
    head->next = second;

    second->data = 53;
    second->next = third;

    third->data = 19;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = head;

    linkedlisttraversal(head);

    printf("linked list after insert value  at first\n");
    head = insertion_at_beginning(head, 15);
    linkedlisttraversal(head);

    // printf("Linked list after insert at index\n");
    // head = insertion_at_index(head, 25, 3);
    // linkedlisttraversal(head);

    // printf("Linked List after insert at end\n");
    // head = insertion_at_end(head, 73);
    // linkedlisttraversal(head);

    // printf("Linked List after insert at specific location\n");
    // head = insertion_by_value(head,60, third);
    // linkedlisttraversal(head);

    // printf("Deletion at first : \n");
    // head = deletion_at_first(head);
    // linkedlisttraversal(head);

    // printf("Deletion at index:\n");
    // head = deletion_at_index(head, 2);
    // linkedlisttraversal(head);

    // printf("deletion at end\n");
    // head = deletion_at_end(head);
    // linkedlisttraversal(head);

    // printf("deletion using any value:\n");
    // head = deletion_by_value(head, second);
    // linkedlisttraversal(head);
    return 0;
}