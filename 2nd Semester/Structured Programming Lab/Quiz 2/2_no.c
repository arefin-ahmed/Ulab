#include <stdio.h>
int main()
{
    int n, max;
    int ar[n];

    printf("Enter the size of array :");
    scanf("%d", &n);
    printf("Enter the numbers :");
    max = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (ar[i] > max)
        {
            max = ar[i];
        }
    }
    printf("The maximum number in an array : %d", max);

    return 0;
}