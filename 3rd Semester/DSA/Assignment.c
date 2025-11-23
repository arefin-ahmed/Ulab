#include <stdio.h>          // Includes standard input/output functions like printf, scanf
#define SIZE 5              // Defines a constant SIZE = 5 for stack & queue limits


/* ---------------- STACK SECTION (Luggage) ---------------- */

int stack[SIZE];            // Declares an integer array 'stack' of size 5
int top = -1;               // 'top' tracks the top index of the stack, -1 means empty


// Function to push luggage into the stack
void push(int tag) {
    if (top == SIZE - 1) {  // Checks if the stack is full
        printf("Stack Overflow! Cannot add luggage.\n");
    } else {
        top++;              // Move to next position
        stack[top] = tag;   // Place luggage tag on the stack
        printf("Luggage %d added successfully.\n", tag);
    }
}


// Function to pop luggage from the stack
void pop() {
    if (top == -1) {        // Checks if the stack is empty
        printf("Stack Underflow! No luggage to remove.\n");
    } else {
        printf("Luggage %d removed.\n", stack[top]); // Show removed luggage
        top--;              // Remove top element by decreasing top
    }
}


// Function to view top element of the stack
void peekStack() {
    if (top == -1) {
        printf("Stack is empty.\n");   // No luggage
    } else {
        printf("Top luggage tag: %d\n", stack[top]); // Shows top luggage
    }
}


// Function to display the full stack
void displayStack() {
    if (top == -1) {
        printf("No luggage on the conveyor.\n");
    } else {
        printf("Luggage on conveyor (Top to Bottom): ");
        for (int i = top; i >= 0; i--)  // Print from top to bottom
            printf("%d ", stack[i]);
        printf("\n");
    }
}


/* ---------------- QUEUE SECTION (Passengers) ---------------- */

int queue[SIZE];            // Circular queue array of size 5
int front = -1, rear = -1;  // Front & rear indexes, -1 means queue is empty


// Adds a passenger to the queue
void enqueue(int id) {
    // Checks for queue overflow (circular queue full condition)
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue Overflow! Passenger cannot enter.\n");
        return;
    }

    if (front == -1) front = 0;   // First insertion — set front to 0

    rear = (rear + 1) % SIZE;     // Move rear forward circularly
    queue[rear] = id;             // Store passenger ID
    printf("Passenger %d added to queue.\n", id);
}


// Removes a passenger from the queue
void dequeue() {
    if (front == -1) {            // Queue empty check
        printf("Queue Underflow! No passenger to remove.\n");
        return;
    }

    printf("Passenger %d checked in.\n", queue[front]);

    if (front == rear)            // Only one element left
        front = rear = -1;        // Queue becomes empty
    else
        front = (front + 1) % SIZE;   // Move front circularly
}


// Shows the next passenger
void peekQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Next passenger ID: %d\n", queue[front]);
    }
}


// Displays all passengers in the queue
void displayQueue() {
    if (front == -1) {
        printf("No passengers waiting.\n");
        return;
    }

    printf("Passengers in queue (Front to Rear): ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);      // Print current passenger
        if (i == rear) break;         // Stop if last passenger printed
        i = (i + 1) % SIZE;           // Move circularly
    }
    printf("\n");
}


/* ---------------- MAIN FUNCTION ---------------- */

int main() {
    int choice, value;

    while (1) {   // Infinite loop for menu
        printf("\n===== AIRPORT AUTOMATION MENU =====\n");

        printf("\nFor Luggage Operations ->\n");
        printf("1. Push Luggage\n");
        printf("2. Pop Luggage\n");
        printf("3. Peek Luggage\n");
        printf("4. Display Luggage\n");

        printf("\nFor Passenger Operations ->\n");
        printf("5. Enqueue Passenger\n");
        printf("6. Dequeue Passenger\n");
        printf("7. Peek Passenger\n");
        printf("8. Display Passengers\n");

        printf("\n9. For Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);      // User selects menu option

        switch (choice) {
            case 1:
                printf("Enter luggage tag: ");
                scanf("%d", &value);
                push(value);       // Call push function
                break;

            case 2:
                pop();             // Call pop
                break;

            case 3:
                peekStack();       // Check top luggage
                break;

            case 4:
                displayStack();    // Show full luggage stack
                break;

            case 5:
                printf("Enter passenger ID: ");
                scanf("%d", &value);
                enqueue(value);    // Add passenger
                break;

            case 6:
                dequeue();         // Remove passenger
                break;

            case 7:
                peekQueue();       // Show front passenger
                break;

            case 8:
                displayQueue();    // Show queue
                break;

            case 9:
                printf("Program Ended.\n");
                return 0;          // Exit program

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
