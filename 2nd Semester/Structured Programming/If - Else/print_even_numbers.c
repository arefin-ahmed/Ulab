#include <stdio.h>
int main()
{
    int i, n;
    printf("Print all even numbers till: \n");
    scanf("%d", &n);
    printf("Even numbers from 1 to %d are: \n", n);
    i = 1;
    while (i<=n)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
        i++;
             
    }
    return 0;
}
