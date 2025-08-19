#include <stdio.h>
int fibonacci(int n)
 {
   if (n==1||n==2)
    return 1;
    return fibonacci (n-1) + fibonacci(n-2);
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n < 1) 
    {
        printf("Number should be >= 1\n");
    } 
    else 
    {
        printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    }

    return 0;
}