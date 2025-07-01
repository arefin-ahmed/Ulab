#include <stdio.h>

int main()

{
    float T,a;
    int choice,c;

    printf("\nSelect the temperature conversion type:\n");
    printf("1. %cC to %cF\n",248,248);
    printf("2. %cC to %cK\n",248,248);
    printf("3. %cF to %cC \n",248,248);
    printf("4. %cF to %cK\n",248,248);
    printf("5. %cK to %cC\n",248,248);
    printf("6. %cK to %cF\n",248,248);
    printf("\nEnter your choice (1-6): ");
    scanf("%d", &choice);

    printf("\nEnter temperature: ");
    scanf("%f", &T);

    switch (choice)
    {
        case 1:
        a = (T * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", T, a);
        break;

    case 2:
        a = T + 273.15;
        printf("%.2f Celsius  = %.2f Kelvin\n", T, a);
        break;

    case 3:
        a = (T - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", T, a);
        break;

    case 4:
        a = (T + 459.67) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Kelvin\n", T,a);
        break;

    case 5:
        a = T - 273.15;
        printf("%.2f Kelvin = %.2f Celsius\n", T,a);
        break;

    case 6:
        a = (T * 9 / 5) - 459.67;
        printf("%.2f Kelvin = %.2f Fahrenheit\n", T,a);
        break;

    default:
        printf("Invalid choice\n");
    }

    return 0;
}
