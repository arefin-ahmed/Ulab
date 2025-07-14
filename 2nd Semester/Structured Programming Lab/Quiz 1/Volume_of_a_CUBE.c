#include <stdio.h>
int main()
{
    int h, w, d, v;

    scanf("%d %d %d", &h, &w, &d);
    printf("Height = %d\nWeight = %d\nDepth = %d\n", h, w, d);

    v = h * w * d;
    printf("Volume = %d", v);

    return 0;
}