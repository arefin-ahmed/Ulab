#include <stdio.h>
int main()
{
    int s,r,per,total_s;

    printf("Input basic salary and percentage\n");
    scanf("%d%d",&s,&per);
    
    r = ((per*s)/100);
    printf("House rent = %d\n",r);

    total_s = s + r;
    printf("Total salary = %d",total_s);

    return 0 ;
}
