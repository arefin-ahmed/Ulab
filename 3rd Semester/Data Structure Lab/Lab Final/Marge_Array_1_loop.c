#include <stdio.h>

int main()
{
    int n1, n2, i;
    int arr1[50], arr2[50], arr3[101];

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    for (i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    for (i = 0; i < n1 + n2; i++)
    {
        if (i < n1)
            arr3[i] = arr1[i];
        else
            arr3[i] = arr2[i - n1];
    }

    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++)
        printf("%d ", arr3[i]);

    return 0;
}
