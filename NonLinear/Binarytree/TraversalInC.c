#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Utility to create a new node
struct node* newNode(int val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// ---------- Inorder Traversal (Left, Root, Right) ----------
void inorder(struct node* root) {
    struct node* stack[100];
    int top = -1;
    struct node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// ---------- Preorder Traversal (Root, Left, Right) ----------
void preorder(struct node* root) {
    if (root == NULL) return;
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right) stack[++top] = curr->right;
        if (curr->left)  stack[++top] = curr->left;
    }
}

// ---------- Postorder Traversal (Left, Right, Root) ----------
void postorder(struct node* root) {
    if (root == NULL) return;
    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    while (top1 != -1) {
        struct node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left)  stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \   /
    //   4   5 6
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
