#include <stdio.h>

int main() 
{
    int num ;
    int i = 1;
    scanf("%d",&num);

    do 
    {
        printf("%d x %d = %d\n", num, i, num * i);
        i++;
    }

    while(i <=10);

    return 0;
}