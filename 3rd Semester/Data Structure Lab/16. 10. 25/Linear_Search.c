#include <stdio.h>

int main()
{
    int n, s, i, arr[101];

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &s);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            printf("%d is found at index: %d", s, i + 1);
            break;
        }

        else
        {
            printf("%d is not found in the array", s);
        }
    }

    return 0;
}
