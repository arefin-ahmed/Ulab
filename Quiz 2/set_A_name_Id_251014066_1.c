#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void delete_begin()
{
    if (head == NULL)
        return;

    struct node *temp = head;
    head = head->next;
    free(temp);
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

    struct node *a = malloc(sizeof(struct node));
    struct node *b = malloc(sizeof(struct node));
    struct node *c = malloc(sizeof(struct node));
    struct node *d = malloc(sizeof(struct node));
    a->data = 10;
    a->next = b;
    b->data = 20;
    b->next = c;
    c->data = 30;
    c->next = d;
    d->data = 40;
    d->next = NULL;
    head = a;

    delete_begin();

    printf("\nAfter deletion operations: ");

    display();

    return 0;
}