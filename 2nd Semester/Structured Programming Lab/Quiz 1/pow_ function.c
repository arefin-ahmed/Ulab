#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, z;

    printf("Enter the value of x\n");
    scanf("%d", &x);

    printf("Enter the value of y\n");
    scanf("%d", &y);

    z = pow(x, 3) + 3 * pow(x, 2) * pow(y, 4) + pow(y, 2);
    printf("z = %d", z);

    return 0;
}