#include <stdio.h>

void traverse(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int main()
{
    int arr[100];
    int size, choice, pos, value, key;

    printf("Enter initial size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Array elements: ");
            traverse(arr, size);
            break;

        case 2:
            printf("Enter position (0-based): ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);

            if (pos < 0 || pos > size)
            {
                printf("Invalid position!\n");
                break;
            }

            for (int i = size; i > pos; i--)
                arr[i] = arr[i - 1];

            arr[pos] = value;
            size++;

            printf("After insertion: ");
            traverse(arr, size);
            break;

        case 3:
            printf("Enter position (0-based): ");
            scanf("%d", &pos);

            if (pos < 0 || pos >= size)
            {
                printf("Invalid position!\n");
                break;
            }

            for (int i = pos; i < size - 1; i++)
                arr[i] = arr[i + 1];

            size--;

            printf("After deletion: ");
            traverse(arr, size);
            break;

        case 4:
            printf("Enter element to search: ");
            scanf("%d", &key);

            int index = linearSearch(arr, size, key);
            if (index != -1)
                printf("Element found at index %d\n", index);
            else
                printf("Element not found\n");
            break;

        case 5:
            printf("Enter position (0-based): ");
            scanf("%d", &pos);
            printf("Enter new value: ");
            scanf("%d", &value);

            if (pos < 0 || pos >= size)
            {
                printf("Invalid position!\n");
                break;
            }

            arr[pos] = value;
            printf("After update: ");
            traverse(arr, size);
            break;

        case 6:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
