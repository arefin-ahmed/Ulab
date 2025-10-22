#include <stdio.h>
int main()
{
    int arr[101], n, pos, i;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= n)
    {
        for (i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\n");

    return 0;
    }
    else
    {
        printf("Invalid position\n");
        return 0;
    }

    
}