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

struct Node *mid(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    

    while (fast!=NULL && fast->next!=NULL)
    { 
        slow =slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
   
    // Create initial list: 10 -> 20 -> 30
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = NULL;
    traverse(head);
    struct Node *middle = mid(head);
    printf("Middle element is: %d\n", middle->data);
    
    return 0;
}
