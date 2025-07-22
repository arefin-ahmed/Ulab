#include <stdio.h>
int main()
{
    int c, f;
    printf("Enter temperature\n");
    scanf("%d",&c);

    f = ((c*9)/5)+32;
    printf("Fahrenheit = %d",f);

    return 0 ;
}