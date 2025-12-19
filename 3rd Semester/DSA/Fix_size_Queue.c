#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Full! Cannot insert %d\n", x);
        return;
    }

    if (front == -1)
        front = 0;
        
    ++rear;
    queue[rear] = x;
    printf("%d enqueued to the queue.\n", x);
}

// Dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Empty! Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue[front++]);
    if (front > rear)      // Reset queue when empty
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
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}




// #include <stdio.h>
// #define MAX 10

// int queue[MAX];
// int front = -1, rear = -1;

// void enqueue(int x)
// {
//     if (rear == MAX - 1)
//     {
//         printf("Queue Full! Cannot insert %d\n", x);
//         return;
//     }

//     if (front == -1)
//         front = 0;

//     queue[++rear] = x;
//     printf("%d enqueued to the queue.\n", x);
// }

// void dequeue()
// {
//     if (front == -1 || front > rear)
//     {
//         printf("Queue Empty! Cannot dequeue.\n");
//         return;
//     }

//     printf("%d dequeued from the queue.\n", queue[front++]);
//     if (front > rear)   
//         front = rear = -1;
// }

// void display()
// {
//     if (front == -1)
//     {
//         printf("Queue is empty.\n");
//         return;
//     }

//     printf("Queue elements (front to rear): ");
//     for (int i = front; i <= rear; i++)
//         printf("%d ", queue[i]);
//     printf("\n");
// }

// int main()
// {
//     int choice, value;

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
//             return 0;
//         default:
//             printf("Invalid choice! Try again.\n");
//         }
//     }

//     return 0;
// }