#include <stdio.h>

int main()
{
    int arr[10], i;
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp1 = arr[8], temp2 = arr[9];
    for (i = 9; i >= 2; i--)
    {
        arr[i] = arr[i - 2];
    }
    arr[0] = temp1;
    arr[1] = temp2;

    printf("After shifting 2 cell :\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}