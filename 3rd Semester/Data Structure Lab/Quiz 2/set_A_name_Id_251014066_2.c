#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int n)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = n;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    front++;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main
{
    enqueue(5);
    enqueue(9);
    enqueue(14);
    dequeue();

    printf("Queue: ");
    display();

    return 0;
}