#include <stdio.h>

int SearchItem(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, x, i, arr[101];

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &x);

    int index = SearchItem(arr, n, x);

    if (index == -1)
    {
        printf("Value is not found in the array\n");
    }
    else
    {
        printf("Value is found at index: %d\n", index);
    }

    return 0;
} 

/* This is not a right way because This only checking if the item is at index 0,
    and treating any other valid index as "not found", which is incorrect.*/

// if (index == 0)
// {
//     printf("Value is found at index: %d", index);
// }
// else
// {
//     printf("Value is not found in the array");
// }