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

// Insert at given position (1-based indexing)
struct Node *insertAtPosition(struct Node *head, int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Case 1: Insert at beginning (pos = 1)
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Case 2: Insert at any middle or end
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main()
{
    // Create initial list: 10 -> 20 -> 30
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data=25;
    new->next=NULL;
    
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    traverse(head);

    // // Insert 5 at beginning (pos=1)
    // head = insertAtPosition(head, 5, 1);
    // printf("After inserting 5 at pos 1: ");
    // traverse(head);

    // // Insert 15 at position 3
    // head = insertAtPosition(head, 15, 3);
    // printf("After inserting 15 at pos 3: ");
    // traverse(head);

    // // Insert 40 at position 6 (end)
    // head = insertAtPosition(head, 40, 6);
    // printf("After inserting 40 at pos 6: ");
    // traverse(head);

    return 0;
}
