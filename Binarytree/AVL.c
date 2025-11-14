#include <stdio.h>
#include <stdlib.h>

// ----------------------------
// AVL NODE STRUCTURE
// ----------------------------
struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

// Get height of a node
int height(struct Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

// Get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ----------------------------
// CREATE NEW NODE
// ----------------------------
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;        // New node is initially at height 1
    return node;
}

// ----------------------------
// RIGHT ROTATION (LL CASE)
// ----------------------------
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;   // New root
}

// ----------------------------
// LEFT ROTATION (RR CASE)
// ----------------------------
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;   // New root
}

// Get balance factor of a node
int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// ----------------------------
// AVL INSERT FUNCTION
// ----------------------------
struct Node* insert(struct Node* node, int key) {

    // 1) NORMAL BST INSERTION
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);

    else
        return node;   // Duplicate keys not allowed

    // 2) UPDATE HEIGHT OF CURRENT NODE
    node->height = 1 + max(height(node->left), height(node->right));

    // 3) GET BALANCE FACTOR
    int balance = getBalance(node);

    // -----------------------------------
    // 4) CHECK 4 CASES OF UNBALANCE
    // -----------------------------------

    // Case 1 – LL Rotation
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2 – RR Rotation
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3 – LR Rotation
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4 – RL Rotation
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // Return unchanged node
}

// ----------------------------
// PREORDER TRAVERSAL
// ----------------------------
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// ----------------------------
// MAIN FUNCTION
// ----------------------------
int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder Traversal of AVL Tree:\n");
    preorder(root);

    return 0;
}
