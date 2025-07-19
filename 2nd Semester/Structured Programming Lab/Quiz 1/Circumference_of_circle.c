#include <stdio.h>
#define pi 3.1416
int main()
{
    float r, c;
    scanf("%f", &r);
    printf("Radius = %.0f\n", r);

    c = 2 * pi * r;
    printf("Circumference of a circle = %.4f", c);

    return 0;
}