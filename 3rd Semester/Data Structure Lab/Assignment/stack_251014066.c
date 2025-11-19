#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Error: Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Error: Stack Underflow! No elements to pop.\n");
    }
    else
    {
        int removed = stack[top];
        top--;
        printf("Popped value: %d\n", removed);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n Stack Menu \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top Element\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
