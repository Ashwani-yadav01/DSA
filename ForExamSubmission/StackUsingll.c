#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// top should be a pointer, not a struct
struct node* top = NULL;

// PUSH operation
void push(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = top;
    top = newNode;

    printf("%d pushed\n", x);
}

// POP operation
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = top;
    printf("%d popped\n", temp->data);

    top = top->next;
    free(temp);
}

// PEEK operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top = %d\n", top->data);
    }
}

// DISPLAY stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    peek();

    display();

    return 0;
}
