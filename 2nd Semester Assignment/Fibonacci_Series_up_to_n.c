#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = 1, b = 1;
    printf("%d, %d", a, b);

    int c = a + b;

    while (c <= n) {
        printf(", %d", c);
        a = b;
        b = c;
        c = a + b;
    }

    return 0;
}
