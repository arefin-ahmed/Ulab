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
    {
        printf("Invalid position\n");
        return;
    }

    new->next = temp->next;
    temp->next = new;
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, x, pos;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insert_begin(x);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &x);
            insert_end(x);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &x);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_pos(x, pos);
            break;

        case 4:
            printf("Numbers: ");
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
