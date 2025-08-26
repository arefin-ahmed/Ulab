#include <stdio.h>
#include <string.h>


int is_palindrome(char str[]) {
    int len = strlen(str);

    for (int left = 0, right = len - 1; left < right; left++, right--) {
        if (str[left] != str[right])
            return 0; 
    }
    return 1; 
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

   
    if (is_palindrome(s))
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}