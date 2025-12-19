#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 0-based indexing
    printf("\nFirst element (arr[0]): %d\n", arr[0]);
    printf("Last element (arr[%d]): %d\n", n - 1, arr[n - 1]);

    // O(1) access
    int index;
    printf("\nEnter index to access element: ");
    scanf("%d", &index);

    if (index >= 0 && index < n)
        printf("Element at index %d is %d (O(1))\n", index, arr[index]);
    else
        printf("Invalid index!\n");

    return 0;
}
