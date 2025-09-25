#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse and print list
void traverse(struct Node *head)
{
   
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next; // Store next node
        curr->next = prev; // Reverse current node's pointer
        prev = curr;       // Move pointers one position ahead
        curr = next;
    }
    return prev; // New head of the reversed list
}
int reverse(struct Node *head)
{
     struct Node *temp1 = head;
    struct Node *next = NULL;
    struct Node *curr = head;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct Node *first = prev;
    struct Node *second = temp1;
    while (first != NULL && second != NULL)
    {
        if (first->data != second->data)
            return 0;

        first=first->next;
        second=second->next;    
    }
    return 1;
}

int main()
{

    // Create initial list: 10 -> 20 -> 30
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    traverse(head);
    head=reverseList(head);
    traverse(head);
   
    
    return 0;
}
