#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse every k nodes
struct Node* reverseKGroup(struct Node* head, int k) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    int count = 0;

    // Check if there are at least k nodes left
    struct Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL)
            return head; // less than k nodes, no reversal
        temp = temp->next;
    }

    // Reverse first k nodes
    count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively reverse remaining nodes
    if (next != NULL)
        head->next = reverseKGroup(next, k);

    return prev; // new head
}

int main() {
    struct Node* head = NULL;

    // Creating a sample linked list 1->2->3->4->5->6->NULL
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Original List:\n");
    printList(head);

    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);

    head = reverseKGroup(head, k);

    printf("Reversed every %d nodes:\n", k);
    printList(head);

    return 0;
}

