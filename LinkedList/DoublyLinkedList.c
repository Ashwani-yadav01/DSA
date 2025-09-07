#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
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
    newNode->prev = NULL;

    newNode->next = head;
    head = newNode;
    return (head);
}

struct Node *insertAtPosition(struct Node *head, int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (pos == 0)
    {
        head = insertAtstart(head, data);
        return head;
    }
    struct Node *temp = head;
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
    newNode->prev = temp;

   if(newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
    return head;
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
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = head;

    // Case 1: Value is in head node
    if (temp->data == data)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    // Case 2: Value is in middle or end
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("The value does not exist\n");
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}
struct Node *deleteAtPosition(struct Node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = head;

    if (pos == 0)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    for (int i = 0; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    

    if (temp == NULL)
    {
        printf("The position is out of bound\n");
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}
int main()
{
    // Create initial list: 10 -> 20 -> 30
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 10;
    head->next = second;
    second->prev = head;
    second->data = 20;
    second->next = third;
    third->prev = second;
    third->data = 30;
    third->next = NULL;
    traverse(head);
    head =deleteAtPosition(head, 1);
    traverse(head);
    return 0;
}
