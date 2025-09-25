#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Function to reverse the doubly linked list
struct Node* reverseDLL(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (originally next)
        current = current->prev;
    }

    // Update head
    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main() {
    // Creating sample DLL: 1 <-> 2 <-> 3 <-> 4
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Original DLL:\n");
    printList(head);

    head = reverseDLL(head);

    printf("Reversed DLL:\n");
    printList(head);

    return 0;
}
