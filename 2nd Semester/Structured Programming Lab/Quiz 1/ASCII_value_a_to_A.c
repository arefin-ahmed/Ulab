#include <stdio.h>
int main()
{
    char l;
    scanf("%c", &l);

    char pre = l - 1;
    char next = l + 1;

    printf("Previous letter %c and ASCII value %d\n", pre, pre);
    printf("Next letter %c and ASCII value %d\n", next, next);

    return 0;
}