#include <stdio.h>

int main() {
    char ch;
    scanf(" %c", &ch);  // Notice the space before %c to ignore any newline

    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32; // Convert to uppercase
    } else if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // Convert to lowercase
    }

    printf("%c", ch);
    return 0;
}
