#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int i;

    if (num >= 1)
    {
        i=1;
        while (i <= num)
        {
            printf("%d ", i);
            i += 1;
        }
    }

    else
    {
        i=-1;
        while (i >= num)
        {
            printf("%d ", i);
            i -= 1;
        }
    }

    return 0;
}
