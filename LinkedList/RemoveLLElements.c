#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the list
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
struct Node *removeElements(struct Node *head, int val)
{
    // Remove all matching nodes at the head
    while (head != NULL && head->data == val)
    {
        struct Node *toDelete = head;
        head = head->next;
        free(toDelete);
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            struct Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    // Creating nodes with given values
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    // Print the list
    traverse(head);
    head = removeElements(head, 6);
    traverse(head);
    return 0;
}