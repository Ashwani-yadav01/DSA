#include <stdio.h>
#include <stdlib.h>

struct list {
    int coeff;
    int pow;
    struct list *next;
};

// Function to add two polynomials
struct list* polyAddition(struct list *poly1, struct list *poly2) {
    struct list *poly3 = NULL, *tail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct list* temp = (struct list*) malloc(sizeof(struct list));
        temp->next = NULL;

        if (poly1->pow > poly2->pow) {
            temp->coeff = poly1->coeff;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            temp->coeff = poly2->coeff;
            temp->pow = poly2->pow;
            poly2 = poly2->next;
        }
        else {
            temp->coeff = poly1->coeff + poly2->coeff;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (poly3 == NULL) {
            poly3 = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // remaining poly1
    while (poly1 != NULL) {
        struct list* temp = (struct list*) malloc(sizeof(struct list));
        temp->coeff = poly1->coeff;
        temp->pow = poly1->pow;
        temp->next = NULL;

        tail->next = temp;
        tail = temp;
        poly1 = poly1->next;
    }

    // remaining poly2
    while (poly2 != NULL) {
        struct list* temp = (struct list*) malloc(sizeof(struct list));
        temp->coeff = poly2->coeff;
        temp->pow = poly2->pow;
        temp->next = NULL;

        tail->next = temp;
        tail = temp;
        poly2 = poly2->next;
    }

    return poly3;
}

// Function to print a polynomial
void printPoly(struct list* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Function to create a new node
struct list* createNode(int coeff, int pow) {
    struct list* node = (struct list*) malloc(sizeof(struct list));
    node->coeff = coeff;
    node->pow = pow;
    node->next = NULL;
    return node;
}

int main() {
    struct list *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, pow;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        struct list* node = createNode(coeff, pow);
        node->next = poly1;
        poly1 = node;
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        struct list* node = createNode(coeff, pow);
        node->next = poly2;
        poly2 = node;
    }

    // Add polynomials
    sum = polyAddition(poly1, poly2);

    // Print result
    printf("Sum of polynomials: ");
    printPoly(sum);

    return 0;
}
