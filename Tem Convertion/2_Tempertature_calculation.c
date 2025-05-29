#include <stdio.h>

int main()

{
    float T;
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

        printf("%.2f Celsius = %.2f Fahrenheit\n", T, (T * 9 / 5) + 32);
        break;

    case 2:
        printf("%.2f Celsius = %.2f Kelvin\n", T, T + 273.15);
        break;

    case 3:
        printf("%.2f Fahrenheit = %.2f Celsius\n", T, (T - 32) * 5 / 9);
        break;

    case 4:
        printf("%.2f Fahrenheit = %.2f Kelvin\n", T, (T + 459.67) * 5 / 9 );
        break;

    case 5:
        printf("%.2f Kelvin = %.2f Celsius\n", T, T - 273.15);
        break;

    case 6:
        printf("%.2f Kelvin = %.2f Fahrenheit\n",T, (T * 9/5) - 459.67);
        break;

    default:
        printf("Invalid choice\n");
    }

    return 0;
}