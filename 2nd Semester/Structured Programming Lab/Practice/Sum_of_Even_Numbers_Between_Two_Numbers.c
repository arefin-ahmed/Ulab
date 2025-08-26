#include <stdio.h>

int main()
{
    int a, b, sum = 0;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }
    printf("Sum of even numbers between %d and %d = %d\n", a, b, sum);
    return 0;
}
