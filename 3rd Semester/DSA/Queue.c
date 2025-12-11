#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Empty\n");
        return;
    }
    front++;
}

void display()
{
    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    printf("Queue: ");
    display();

    return 0;
}
