#include <stdio.h>
int main()
{
    int num ;
    int sum=0;
    int i=1;
    scanf("%d",&num);

    do
    {
        sum+=i;
        i+=1;
    }
    while(i<=num);
    printf("sum is %d",sum);

    return 0 ;
}