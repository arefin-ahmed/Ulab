#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = head;
    head = new;
}

void insert_end(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
}

void insert_pos(int x, int pos)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;

    if (pos == 1)
    {
        new->next = head;
        head = new;
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    new->next = temp->next;
    temp->next = new;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert_begin(10);
    insert_end(20);
    insert_pos(15, 2);

    printf("Linked List: ");
    display();

    return 0;
}
