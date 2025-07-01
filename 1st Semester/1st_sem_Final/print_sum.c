#include <stdio.h>
int main()
{
    int num, sum = 0;
    scanf("%d", &num);
    int i = 1;
    while (i <= num)
    {
        sum += i;
        i += 1;
    }
    printf("sum is %d", sum);

    return 0;
}
