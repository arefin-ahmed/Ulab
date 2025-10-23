#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int select, minIndex, minValue;

    for (select = 0; select < (n - 1); select++)
    {
        minIndex = select;

        for (int i = select + 1; i < n; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        int tmp;
        tmp = arr[minIndex];
        arr[minIndex] = arr[select];
        arr[select] = tmp;
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