#include <stdio.h>
int main()
{
    int n;
    printf("Enter nth term : ");
    scanf("%d", &n);

    int sum = 0, fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
        sum = sum + fact;
    }

    printf("Sum of the series up to %d th terms is: %d\n", n, sum);

    return 0;
}