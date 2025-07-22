#include <stdio.h>
int main()
{
    int a ,b, c;
    int large, small,even,odd;
    scanf("%d%d%d",&a,&b,&c);

    if (a>b&&a>c)
        large = a;
    else if (b>a&&b>c)
        large = b;
    else
       large = c;


    if (a<b&&a<c)
        small = a;
    else if (b<a&&b<c)
        small = b;
    else
        small = c;


    if(large%2==0)
        even;
    else
        odd;

    printf("Largest number is %d & it is %d",large,even);
    return 0 ;
}