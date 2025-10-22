#include <stdio.h>
int main()
{
    int arr1[101], arr2[101], arr3[301];
    int s1, s2, i, j;

    printf("Enter the number of element in 1st array: ");
    scanf("%d", &s1);

    for (i = 0; i < s1; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
        arr3[i] = arr1[i];
    }

    printf("Enter the number of element in 2nd array: ");
    scanf("%d", &s2);

    for (i = 0; i < s2; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr2[i]);
        arr3[i + s1] = arr2[i];
    }

    printf("Merged array: ");
    for (i = 0; i < s1 + s2; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
} 