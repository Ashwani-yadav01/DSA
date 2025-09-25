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

struct Node *insertAtstart(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = head;
    head = newNode;
    return (head);
}
struct Node *insertAtPosition(struct Node *head, int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node *temp = head;
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
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

struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return (head);
}

struct Node *updateAtPosition(struct Node *head, int data, int pos)
{

    struct Node *temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range!\n");
        return head;
    }
    temp->data = data;
    return head;
}

struct Node *deleteAtValue(struct Node *head, int data)
{
    struct Node *temp = head;
    struct Node *prev;
    while (temp->data != data && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("the value does not exist\n");
        return head;
    }
    prev->next = temp->next;
    temp->next = NULL;
    return head;
}
struct Node *deleteAtPosition(struct Node *head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    // Delete head
    if (pos == 0) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    // Traverse to the node to delete
    for (int i = 0; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bound\n");
        return head;
    }

    // Remove node
    prev->next = temp->next;
    free(temp);
    return head;
}
int main()
{
    // Create initial list: 10 -> 20 -> 30
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *four = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = four;
    four->data = 40;
    four->next = NULL;
    traverse(head);
    head = deleteAtPosition(head,  1);
    traverse(head);
    return 0;
}
