#include <stdio.h>

#define MAX 10 // Maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Index of the top element in the stack (-1 means empty)

/*
---------------------------------------------------------
 Function: push
 Purpose : Add an element to the top of the stack
 Logic   : Increment 'top' and place the element there
           Check for stack overflow before adding
---------------------------------------------------------
*/
void push(int value)
{
    if (top == MAX - 1)
    { // Stack is full
        printf("Error: Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        top++;              // Move top pointer up
        stack[top] = value; // Insert element
        printf("%d pushed onto the stack.\n", value);
    }
}

/*
---------------------------------------------------------
 Function: pop
 Purpose : Remove the top element from the stack
 Logic   : Check for underflow, print and remove top element,
           then decrement 'top'
---------------------------------------------------------
*/
void pop()
{
    if (top == -1)
    { // Stack is empty
        printf("Error: Stack Underflow! No elements to pop.\n");
    }
    else
    {
        int removed = stack[top]; // Store top element
        top--;                    // Remove it
        printf("Popped value: %d\n", removed);
    }
}

/*
---------------------------------------------------------
 Function: peek
 Purpose : Display the top element without removing it
 Logic   : Check if stack is empty
---------------------------------------------------------
*/
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

/*
---------------------------------------------------------
 Function: display
 Purpose : Display all elements of the stack from top to bottom
 Logic   : Loop from 'top' to 0 to print elements
---------------------------------------------------------
*/
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

/*
---------------------------------------------------------
 Function: main
 Purpose : Menu-driven program for stack operations
 Logic   : User chooses an operation repeatedly until exit
           Operations: push, pop, peek, display, exit
---------------------------------------------------------
*/
int main()
{
    int choice, value;

    while (1)
    { // Infinite loop for menu
        // Display menu options
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice)
        {
        case 1: // Push operation
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2: // Pop operation
            pop();
            break;

        case 3: // Peek operation
            peek();
            break;

        case 4: // Display stack
            display();
            break;

        case 5: // Exit program
            printf("Exiting program...\n");
            return 0;

        default: // Invalid input
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
