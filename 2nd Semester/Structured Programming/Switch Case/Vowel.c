#include <stdio.h>
int main()
{
    char alphabet;
    printf("Enter an alphabet : \n");
    scanf("%c", &alphabet);
    switch (alphabet)
    {
    case 'a':
        printf("Alphabet a is vowel.\n");
        break;
    case 'e':
        printf("Alphabet e is vowel.\n");
        break;
    case 'i':
        printf("Alphabet i is vowel.\n");
        break;
    case 'o':
        printf("Alphabet o is vowel.\n");
        break;
    case 'u':
        printf("Alphabet u is vowel.\n");
        break;
    default:
        printf("You entered a consonant.\n");
    }
    return 0;
}