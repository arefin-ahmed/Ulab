#include <stdio.h>
int main()
{
    int number;

    scanf("%d", &number);
    printf("Enter the number: %d\n", number);

    if (number >= 90)
    {
        printf("Grade A+");
    }

    else if (number >= 80)
    {
        printf("Grade A");
    }

    else if(number >= 70)
    {
        printf("Grade A-");
    }

    else if(number >= 60)
    {
        printf("Grade B+");
    }

    else if(number >= 50)
    {
        printf("Grade B");
    }

    else if(number >= 40)
    {
        printf("Grade B-");
    }

    else if(number <= 40)
    {
        printf("Fail");
    }

    return 0;
}