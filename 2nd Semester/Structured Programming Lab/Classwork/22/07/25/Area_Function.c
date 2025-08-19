// Process - 1
/*#include <stdio.h>
#define pi 3.1416

float triangle (float b, float h)
{
    return 0.5*b*h;
}

float square (float a)
{
        return a*a;
}

float circle (float r)
{
        return pi*r*r;
}

    int main()
{
    float b,h,a,r;

    printf("Enter the base and height ");
    scanf("%.2f%.2f",&b,&h);
    printf("Area of Triangle = %d\n",triangle);

    printf("Enter the arm ");
    scanf("%f%f",&b,&h);
    printf("Area of Square = %d\n",square);

    printf("Enter the redius ");
    scanf("%f%f",&b,&h);
    printf("Area of Circle = %d\n",circle);

    return 0 ;
}*/
                            // Process - 2
#include <stdio.h>

float squareArea(float arm)
{
    return arm * arm;
}

int main()
{
    float arm;
    printf("Enter arms of the square: ");
    scanf("%f", &arm);

    printf("Area of the square is: %.2f\n", squareArea(arm));

    return 0;
}