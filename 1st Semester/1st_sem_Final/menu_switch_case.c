#include <stdio.h>
int main()
{
    int ch;

    do
    {
        printf("\nMenu:\n1. Hi\n2. Bye\n3. Exit\n");
        printf("Enter Choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Hi");
            break;

        case 2:
            printf("Bye");
            break;

        case 3:
            printf("Exit");
            break;

        default:
            printf("Invalid Choice");
        }

    } 
    
    while (ch != 3);

    return 0;
}