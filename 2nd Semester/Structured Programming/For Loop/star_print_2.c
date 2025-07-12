// #include <stdio.h>
// int main()
// {
//     int i, j, k;

//     for (i = 1; i <= 5; i++)
//     {
//         for (j = 4; j >= 5 - i; j--)
//         {
//             printf(" ");
//         }

//         for (k = 1; k != 2 * i - 1; k++)
//         {
//             printf("%d",k);
//         }

//         printf("\n");
//     }

//     return 0;
// }

#include <stdio.h>
int main()
{
    int i, j, k;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5 - i; j++)
        {
            printf(" ");
        }
        int n = 1;
        for (k = 0; k != 2 * i - 1; k++)
        {
            printf("%d", n);
            n++;
        }

        printf("\n");
    }

    return 0;
}