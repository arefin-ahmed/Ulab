#include <stdio.h>
int main()
{
   float a, b;
   char operation, choice;
  
   {
      while (1)
      {

      printf("\nEnter Num:");
      scanf("%f", &a);
      printf("Enter Num:");
      scanf("%f", &b);
      printf("Enter operation(+,-,*/):");
      scanf(" %c", &operation);
      switch (operation)
      {
      case '+':
         printf("a+b:%.2f", a + b);
         break;

      case '-':
         printf("a-b:%.2f", a - b);
         break;

      case '*':
         printf("a*b:%.2f", a * b);
         break;

      case '/':
         printf("a/b:%.2f", a / b);
         break;

      default:
         printf("Invalid Operation");
      }
   }

   }
   return 0;
}