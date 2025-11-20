#include <stdio.h>

int main()
{
    int n = 0, m, pos, arr1[100];

    while (1)
    {
        printf("\n--- Operations ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Exit\n");
        printf("Enter the operation: ");
        if (scanf("%d", &m) != 1)
            break;

        if (m == 1)
        {
            if (n >= 100)
            {
                printf("Array is full. Cannot insert more elements.\n");
                continue;
            }
            int val;
            printf("Enter the element to add: ");
            if (scanf("%d", &val) != 1)
                break;
            printf("Enter the position to insert (0 to %d): ", n);
            if (scanf("%d", &pos) != 1)
                break;
            if (pos < 0 || pos > n)
            {
                printf("Invalid position.\n");
                continue;
            }
            for (int i = n; i > pos; i--)
            {
                arr1[i] = arr1[i - 1];
            }
            arr1[pos] = val;
            n++;
            printf("Array after insertion: ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr1[i]);
            printf("\n");
        }
        else if (m == 2)
        {
            if (n == 0)
            {
                printf("Array is empty. Nothing to delete.\n");
                continue;
            }
            printf("Enter the position to delete (0 to %d): ", n - 1);
            if (scanf("%d", &pos) != 1)
                break;
            if (pos < 0 || pos >= n)
            {
                printf("Invalid position.\n");
                continue;
            }
            for (int i = pos; i < n - 1; i++)
            {
                arr1[i] = arr1[i + 1];
            }
            n--;
            printf("Array after deletion: ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr1[i]);
            printf("\n");
        }
        else if (m == 3)
        {
            break;
        }
        else
        {
            printf("Invalid Menu\n");
        }
    }

    return 0;
}


