#include <stdio.h>
int main(void)
{
    int n, m, pos, arr1[100], arr2[100];

    while (1)
    {

        printf("\n--- Oparetions ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("Enter the oparetion: ");
        scanf("%d", m);

        if (m == 1)
        {
            printf("Enter the element to add: ");
            for (int i = 0; i < n; i++)
            {
                printf("Arr[%d] = ", i);
                scanf("%d", &arr1[i]);
            }
        }

        if (m == 2)
        {
            printf("Enter the element to delete: ");
            for (int i = n - 1; i >= pos; i--)
            {
                printf("Arr[%d] = ", i);
                printf("arr1[i]", n);
            }
        }
    }

    return 0;
}