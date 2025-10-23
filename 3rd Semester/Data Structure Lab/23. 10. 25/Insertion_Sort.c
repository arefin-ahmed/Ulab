#include <stdio.h>
void sort(int arr[], int n)
{
    int i, key;
    for (int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;

        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
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

    sort(arr, n);
    printf("Sorted Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}