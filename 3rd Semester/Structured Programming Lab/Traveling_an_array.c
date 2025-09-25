#include <stdio.h>
int main()
{
    int arr[20], n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n > 20)
    {
        printf("Number of elements should not exceed 20.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array of elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
