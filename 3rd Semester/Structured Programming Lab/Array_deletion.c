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

    return 0;
}