#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// ---------- INSERTION ----------
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return create(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// ---------- FIND MINIMUM NODE ----------
struct node* minNode(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// ---------- DELETION ----------
struct node* delete(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) { // no child
            free(root);
            return NULL;
        }
        else if (root->left == NULL) { // one right child
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) { // one left child
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else { // two children
            struct node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// ---------- INORDER TRAVERSAL ----------
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ---------- MAIN FUNCTION ----------
int main() {
    struct node* root = NULL;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);

    printf("Inorder before deletion: ");
    inorder(root);
    printf("\n");

    root = delete(root, 20);
    printf("After deleting 20: ");
    inorder(root);
    printf("\n");

    root = delete(root, 40);
    printf("After deleting 40: ");
    inorder(root);
    printf("\n");

    return 0;
}

