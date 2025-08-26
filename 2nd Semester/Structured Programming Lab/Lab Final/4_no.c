#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b;
    printf("Enter two numbers\nFirst Number: ");
    scanf("%d", &a);
    printf("Second Number: ");
    scanf("%d", &b);

    swap(&a, &b);

    printf("After swapping >>\nFirst Number: = %d, Second Number: = %d\n", a, b);

    return 0;
}