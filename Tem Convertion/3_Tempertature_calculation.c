#include <stdio.h>
#include <stdlib.h>

int main()
{
   while(1)
   {
   float temp;
   int choice;

   printf("Temperature Converter\n");
   printf("Select the conversion type:\n");
   printf("1. Celsius to Fahrenheit\n");
   printf("2. Celsius to Kelvin\n");
   printf("3. Fahrenheit to Celsius\n");
   printf("4. Fahrenheit to Kelvin\n");
   printf("5. Kelvin to Celsius\n");
   printf("6. Kelvin to Fahrenheit\n");
   printf("7. Exit\n");
   printf("Enter your choice (1-7): ");
   scanf("%d", &choice);

   switch (choice)
   {
   
   case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temp);
      printf("%.2f Celsius = %.2f Fahrenheit\n", temp, (temp * 9 / 5) + 32);
      break;
   case 2:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temp);
      printf("%.2f Celsius = %.2f Kelvin\n", temp, temp + 273.15);
      break;
   case 3:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temp);
      printf("%.2f Fahrenheit = %.2f Celsius\n", temp, (temp - 32) * 5 / 9);
      break;
   case 4:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temp);
      printf("%.2f Fahrenheit = %.2f Kelvin\n", temp, (temp - 32) * 5 / 9 + 273.15);
      break;
   case 5:
      printf("Enter temperature in Kelvin: ");
      scanf("%f", &temp);
      printf("%.2f Kelvin = %.2f Celsius\n", temp, temp - 273.15);
      break;
   case 6:
      printf("Enter temperature in Kelvin: ");
      scanf("%f", &temp);
      printf("%.2f Kelvin = %.2f Fahrenheit\n", temp, (temp - 273.15) * 9 / 5 + 32);
      break;
      case 7:
      printf("Exit");
      exit(0);
      break;
   default:
      printf("Invalid choice. Please select a number between 1 and 6.\n");
   
   }

   }
   return 0;
}
