#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

// Push function
void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Overflow! Cannot push %d\n", x);
        return;
    }
    stack[++top] = x;
    printf("%d pushed to stack.\n", x);
}

// Pop function
void pop()
{
    if (top == -1)
    {
        printf("Underflow! Stack is empty.\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Display function
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
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
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
