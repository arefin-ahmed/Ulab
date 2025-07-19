#include <stdio.h>
#define pi 3.1416
int main()
{
    float r, a;
    scanf("%f", &r);
    printf("Radius = %.0f\n", r);

    a = pi*r*r;
    printf("Area of a circle = %.4f", a);

    return 0 ;
}