#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
};
void traverse(struct list *head)
{
    struct list *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct list *insertAthead(struct list *node)
{
    if (node == NULL)
    {
        int item;
        printf("Enter the item ");
        scanf("%d", &item);
        struct list *new = (struct list *)malloc(sizeof(struct list *));
        new->data = item;
        new->next = NULL;
        node = new;
        return node;
    }

    int item;
    printf("Enter the item ");
    scanf("%d", &item);
    struct list *new = (struct list *)malloc(sizeof(struct list *));
    new->data = item;
    new->next = node;
    node = new;
    return node;
}

struct list *insertAtLast(struct list *node)
{
    int item;
    printf("Enter the item ");
    scanf("%d", &item);
    struct list *new = (struct list *)malloc(sizeof(struct list *));
    new->data=item;
    new->next=NULL;
    struct list *temp=node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    return node;
}
struct list *create(int n, struct list *node)
{
    struct list *new = (struct list *)malloc(sizeof(struct list *));
    if (new == NULL)
    {
        printf("Node not created");
    }
    else if (node == NULL)
    {
        int item;
        printf("Enter the item ");
        scanf("%d", &item);
        new->data = item;
        new->next = NULL;
        node = new;
    }
    struct list *temp = node;
    for (int i = 1; i < n; i++)
    {
        int item;
        printf("Enter the item ");
        scanf("%d", &item);
        struct list *new1 = (struct list *)malloc(sizeof(struct list *));
        new1->data = item;
        new1->next = NULL;
        temp->next = new1;
        temp = temp->next;
    }
    return node;
}
int main()
{
    int n;
    printf("enter the size of list ");
    scanf("%d", &n);
    struct list *node = NULL;
    node = create(n, node);
    traverse(node);
    node = insertAthead(node);
    traverse(node);
    node = insertAtLast(node);
    traverse(node);
    return 0;
}