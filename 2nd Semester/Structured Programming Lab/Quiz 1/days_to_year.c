#include <stdio.h>
int main()
{
    int d,y,m,w;
    printf("Input days\n");
    scanf("%d",&d);

    y = d/365;
    d = d % 365;    // remaining days for month

    m = d/30;
    d= d % 30;     // remaining days for week and days

    w = d/7;
    d = d%7;
    printf("%d years %d months %d weeks %d days",y,m,w,d);
        

    return 0 ;
}
