#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of a=%d and b=%d is c=%d\n", a, b, c);

  int x = 0;
  int y = 0;
  x = c;
  y = a;
  a = x;
  c = y; 


  printf("Now, a = %d\n", a);
  printf("And c = %d\n", c);
}
