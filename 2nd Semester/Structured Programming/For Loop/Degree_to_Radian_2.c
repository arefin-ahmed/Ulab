#include <stdio.h>
#define PI 3.1416
int main()
{
    int degrees ;
    float radians;
    printf("Degrees to Radians \n");

    for(degrees= 10;degrees<=360;degrees+=10)
    {
        radians = degrees * PI / 180;
        printf("%d = %.4f \n", degrees, radians);
        
    }
    return 0;
}