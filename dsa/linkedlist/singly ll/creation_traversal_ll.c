#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr) // points to the head node
{
    while (ptr != NULL)
    {
        printf("Elmenent: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    // allocate memory for nodes in the nexted list in heap
    head = (struct Node *)malloc(sizeof(struct Node)); /* head is a struct pointer */
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
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

    linkedlisttraversal(head);

    return 0;
}