#include <stdio.h>
#define PI 3.1416
int main()
{
    int degrees = 10;
    float radians;
    printf("Degrees to Radians \n");
    while (degrees <= 360)
    {

        radians = degrees * PI / 180;
      printf("%d = %.4f \n", degrees, radians);
      degrees += 10;
    }
    return 0;
}