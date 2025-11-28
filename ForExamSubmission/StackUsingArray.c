#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    peek();
    display();

    return 0;
}
