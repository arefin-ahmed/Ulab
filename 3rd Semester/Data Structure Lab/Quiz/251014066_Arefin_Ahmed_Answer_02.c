#include <stdio.h>
int main()
{
    int n, pos, arr1[100];


    printf("Enter the element to add: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Arr[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    

    return 0;
}