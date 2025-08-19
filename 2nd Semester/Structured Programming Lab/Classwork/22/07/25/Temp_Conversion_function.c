#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    float c, f;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);
    printf("%.2f Celsius = %.2f Fahrenheit\n", c, celsiusToFahrenheit(c));

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &f);
    printf("%.2f Fahrenheit = %.2f Celsius\n", f, fahrenheitToCelsius(f));

    return 0;
}
