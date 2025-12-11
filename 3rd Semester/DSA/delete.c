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

void delete_end()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void delete_pos(int pos)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
        return;

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
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
    a->data = 10;
    a->next = b;
    b->data = 20;
    b->next = NULL;
    head = a;

    delete_begin();
    delete_end();

    printf("Linked List: ");
    display();

    return 0;
}
