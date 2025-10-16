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
    int n, x, i, arr[n];
    int result = SearchItem(arr, n, x);

    printf("Enter the number of element in array: ");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &x);

    if (result == -1)
    {
        printf("Value is not found in the array");
    }
    else
    {
        printf("Value is found at location: %d", result);
    }
    return 0;
}