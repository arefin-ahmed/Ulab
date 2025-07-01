#include <stdio.h>

int main()
{
    int numbers[5];
    int i, largest, smallest;

    printf("Enter five integers: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    largest = smallest = numbers[0];

    for (i = 1; i < 5; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
        if (numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
    }

    printf("\nLargest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

    return 0;
}
