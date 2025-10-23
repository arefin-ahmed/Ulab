#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int j, minIndex, minValue;

    for (j = 0; j < (n - 1); j++)
    {
        minIndex = j;

        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        int tmp;
        tmp = arr[minIndex];
        arr[minIndex] = arr[j];
        arr[j] = tmp;
    }
}

int main()
{
    int n, x;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}