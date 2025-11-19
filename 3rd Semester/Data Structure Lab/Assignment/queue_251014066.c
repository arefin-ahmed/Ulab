#include <stdio.h>
#define SIZE 5

int front = -1;
int rear = -1;
int queue[SIZE];

void enqueue(int n)
{
    if (rear == SIZE - 1)
    {
        printf("Sorry, the queue is full at the moment!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = n;
        printf("%d enqueued to the queue.\n", n);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("The queue is empty right now!\n");
    }
    else
    {
        int value = queue[front];
        printf("Dequeued value is: %d\n", value);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void printQueue()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    do
    {
        printf("\nQueue Menu:\n");
        printf("1: Enqueue an element\n");
        printf("2: Dequeue an element\n");
        printf("3: Display all elements\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int item;
            printf("Enter element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        }
        case 2:
            dequeue();
            break;
        case 3:
            printQueue();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (ch != 4);

    return 0;
}
