#include <stdio.h>

int main()
{
    int i, n, num, pos, arr[100];

    // Ask the user how many elements are currently in the array
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    // Read all array elements from user
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i); // Display index
        scanf("%d", &arr[i]);    // Store value at arr[i]
    }

    // Ask the user which number they want to insert
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &num);

    // Ask the user the position where the new number should be inserted
    printf("Enter the position at which the number has to be added: ");
    scanf("%d", &pos);

    /*
       SHIFTING ELEMENTS TO THE RIGHT
       ---------------------------------
       Start from the last element (n-1)
       Move each element one position ahead
       Stop when we reach the insertion position
       This creates an empty space at arr[pos]
    */
    for (i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i]; // Shift element to the right
    }

    // Insert the new number at the required position
    arr[pos] = num;

    // Increase array size because one element is added
    n = n + 1;

    // Display the final array after insertion
    printf("\nThe array after insertion of %d is:\n", num);

    for (i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
