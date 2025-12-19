#include <stdio.h>

int main()
{
    int n1, n2, i;
    int arr1[50], arr2[50], arr3[50];

    printf("Enter the number of elements for 1st Array: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    printf("\n");
    printf("Enter the number of elements for 2nd Array: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    printf("\nFirst Array: ");
    for (i = 0; i < n1; i++)
        printf("%d ", arr1[i]);

    printf("\nSecond Array: ");
    for (i = 0; i < n2; i++)
        printf("%d ", arr2[i]);

    printf("\nMerged Array: ");
    for (i = 0; i < n1; i++)
        printf("%d ", arr1[i]);
    for (i = 0; i < n2; i++)
        printf("%d ", arr2[i]);

    return 0;
}