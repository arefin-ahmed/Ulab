#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    printf("Enter a string : ");
    scanf("%s", s);

    if (is_palindrome(s))
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}