#include <stdio.h>

int main()
{
    int n1, n2, n3, n4, n5;
    int largest, smallest;

    printf("Enter five integers:\n");

    printf("Number 1:");
    scanf("%d", &n1);

    printf("Number 2:");
    scanf("%d", &n2);

    printf("Number 3:");
    scanf("%d", &n3);

    printf("Number 4:");
    scanf("%d", &n4);

    printf("Number 5:");
    scanf("%d", &n5);

    largest = n1;
    smallest = n1;

    if(n2 > largest) largest = n2;
    if(n2 < smallest) smallest = n2;
    
    if(n3 > largest) largest = n3;
    if(n3 < smallest) smallest = n3;
    
    if(n4 > largest) largest = n4;
    if(n4 < smallest) smallest = n4;
    
    if(n5 > largest) largest = n5;
    if(n5 < smallest) smallest = n5;

    printf("\nLargest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

    return 0;
}
