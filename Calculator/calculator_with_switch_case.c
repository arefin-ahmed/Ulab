#include <stdio.h>
int main()
{
   float a, b;
   char operator;

   printf("Enter 1st Number:\n");
   scanf("%f", &a);
   printf("Enter operator(+,-,*,/):\n");
   scanf(" %c", &operator);
   printf("Enter 2nd Number:\n");
   scanf("%f", &b);

   switch (operator)
   {
   case '+':
      printf("a+b=%.2f", a + b);
      break;

   case '-':
      printf("a-b=%.2f", a - b);
      break;

   case '*':
      printf("a*b=%.2f", a * b);
      break;

   case '/':
      if (b != 0)
      {
         printf("a / b = %.2f\n", a / b);
      }
      else
      {
         printf("Cannot divide by zero\n");
      }

      break;

   default:
      printf("Invalid operator");
   }
   return 0;
}