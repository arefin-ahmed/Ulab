#include <stdio.h>

int main()
{
    int arr1[20], arr2[20], merged[40];
    int n1, n2, i, j;

    // Read size of first array
    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);

    // Read elements of first array
    for (i = 0; i < n1; i++)
    {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }

    // Read size of second array
    printf("\nEnter the number of elements in second array: ");
    scanf("%d", &n2);

    // Read elements of second array
    for (i = 0; i < n2; i++)
    {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    // STEP 1: Copy arr1 into merged[]
    for (i = 0; i < n1; i++)
    {
        merged[i] = arr1[i];   // Copy elements of first array
    }

    // STEP 2: Copy arr2 after arr1 elements
    for (j = 0; j < n2; j++)
    {
        merged[i] = arr2[j];   // i still holds n1 (end of arr1)
        i++;
    }

    // Total size of merged array = n1 + n2
    int total = n1 + n2;

    // Display merged array
    printf("\nThe merged array is:\n");
    for (i = 0; i < total; i++)
    {
        printf("merged[%d] = %d\n", i, merged[i]);
    }

    return 0;
}