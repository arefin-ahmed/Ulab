#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1;
int maxSize;

// Enqueue 
void enqueue(int x)
{
    if ((rear + 1) % maxSize == front)
    {
        printf("Queue is full. Cannot insert %d\n", x);
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % maxSize;
    queue[rear] = x;
    printf("%d enqueued to the queue.\n", x);
}

// Dequeue
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue[front]);
    if (front == rear)
    {                                                          // Queue becomes empty
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % maxSize;
    }
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
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % maxSize;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &maxSize);

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
            free(queue);
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// int *queue;
// int front = -1, rear = -1;
// int maxSize;

// void enqueue(int x)
// {
//     if ((rear + 1) % maxSize == front)
//     {
//         printf("Queue is full. Cannot insert %d\n", x);
//         return;
//     }

//     if (front == -1)
//         front = 0;

//     rear = (rear + 1) % maxSize;
//     queue[rear] = x;
//     printf("%d enqueued to the queue.\n", x);
// }

// void dequeue()
// {
//     if (front == -1)
//     {
//         printf("Queue is empty. Cannot dequeue.\n");
//         return;
//     }

//     printf("%d dequeued from the queue.\n", queue[front]);
//     if (front == rear)
//     {                    
//         front = rear = -1;
//     }
//     else
//     {
//         front = (front + 1) % maxSize;
//     }
// }

// void display()
// {
//     if (front == -1)
//     {
//         printf("Queue is empty.\n");
//         return;
//     }

//     printf("Queue elements (front to rear): ");
//     int i = front;
//     while (1)
//     {
//         printf("%d ", queue[i]);
//         if (i == rear)
//             break;
//         i = (i + 1) % maxSize;
//     }
//     printf("\n");
// }

// int main()
// {
//     int choice, value;

//     printf("Enter the size of the queue: ");
//     scanf("%d", &maxSize);

//     queue = (int *)malloc(maxSize * sizeof(int));
//     if (!queue)
//     {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }

//     while (1)
//     {
//         printf("\n--- Queue Operations Menu ---\n");
//         printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter value to enqueue: ");
//             scanf("%d", &value);
//             enqueue(value);
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             printf("Exiting program.\n");
//             free(queue);
//             return 0;
//         default:
//             printf("Invalid choice! Try again.\n");
//         }
//     }

//     return 0;
// }
