// User define size Queue Using Array

#include <stdio.h>
#include <stdlib.h>

int *queue; // Pointer for dynamic queue
int front = -1, rear = -1;
int maxSize; // User-defined size

// Enqueue function
void enqueue(int x)
{
    if (rear == maxSize - 1)
    {
        printf("Queue is full. Cannot insert %d\n", x);
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = x;
    printf("%d enqueued to the queue.\n", x);
}

// Dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue[front++]);
    if (front > rear)                            // Reset queue when empty
        front = rear = -1;
}

// Display function
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int choice, value;

    // Get user-defined size
    printf("Enter the size of the queue: ");
    scanf("%d", &maxSize);

    // Allocate memory dynamically for the queue
    queue = (int *)malloc(maxSize * sizeof(int));
    if (!queue)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1)
    {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            free(queue); // Free dynamically allocated memory
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
