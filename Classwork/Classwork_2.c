#include <stdio.h>

int main()

{
    int n, i, choice;
    while (1)
    {
    printf("\n1. Even\n2. Odd\n3. Exit\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter the number: ");
        scanf("%d", &n);
        i = 2;
        while (i <= n)
        {
            printf("%d\n", i);
            i = i + 2;
        }
        break;

    case 2:
        printf("Enter the number: ");
        scanf("%d", &n);
        i = 1;
        while (i <= n)
        {
            printf("%d\n", i);
            i = i + 2;
        }
        break;

    case 3:
        printf("Exiting program.\n");
        break;

    default:
        printf("Invalid choice. Please select a number between 1 to 3\n");
        
    }
    }
    return 0;
}
