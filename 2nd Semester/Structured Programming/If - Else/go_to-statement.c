#include <stdio.h>
int main()
{
    int i = 10;

    repeat:
    printf("%d \n", i);
    i++;
    if (i < 20)
    {
        goto repeat;
    }

    return 0;
}