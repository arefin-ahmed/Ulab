#include <stdio.h>

int main()
{
    int i, n, arr[20]; // i = loop counter, n = number of elements, arr = integer array of size 20

    // Ask the user for the number of elements
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n); // Read the value of n

    // Input (Traverse array to read values)
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i); // Display index number
        scanf("%d", &arr[i]);    // Store value in array
    }

    // Output (Traverse array to display values)
    printf("\nThe array elements are: ");

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]); // Print each element
    }

    return 0; // End of program
}