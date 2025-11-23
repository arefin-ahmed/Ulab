#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

/* ---------------- STACK SECTION (Luggage) ---------------- */

int stack[SIZE];
int top = -1;

void push(int tag)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow! Cannot add luggage.\n");
    }
    else
    {
        top++;
        stack[top] = tag;
        printf("Luggage %d added successfully.\n", tag);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No luggage to remove.\n");
    }
    else
    {
        printf("Luggage %d removed.\n", stack[top]);
        top--;
    }
}

void peekStack()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top luggage tag: %d\n", stack[top]);
    }
}

void displayStack()
{
    if (top == -1)
    {
        printf("No luggage on the conveyor.\n");
    }
    else
    {
        printf("Luggage on conveyor (Top to Bottom): ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

/* ---------------- QUEUE SECTION (Passengers) ---------------- */

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int id)
{
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front))
    {
        printf("Queue Overflow! Passenger cannot enter.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = id;

    printf("Passenger %d added to queue.\n", id);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow! No passenger to remove.\n");
        return;
    }

    printf("Passenger %d checked in.\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void peekQueue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Next passenger ID: %d\n", queue[front]);
    }
}

void displayQueue()
{
    if (front == -1)
    {
        printf("No passengers waiting.\n");
        return;
    }

    printf("Passengers in queue (Front to Rear): ");
    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

//  ---------------- MAIN FUNCTION ---------------- 

int main()
{
    int choice, value;

    while (1)
    {
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
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter luggage tag: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peekStack();
            break;

        case 4:
            displayStack();
            break;

        case 5:
            printf("Enter passenger ID: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 6:
            dequeue();
            break;

        case 7:
            peekQueue();
            break;

        case 8:
            displayQueue();
            break;

        case 9:
            printf("Program Ended.\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}