#include <stdio.h>

void main (void) {

int a = 545;
float b = 545.5;
char c = 'h';
double d = 545.5;


  printf ("int a value %d size %d bytes.\n", a, sizeof(a));
  printf ("float a value %f size %d bytes.\n", b, sizeof(b));
  printf ("character a value %c size %d bytes.\n", c, sizeof(c));
  printf ("double a value %f size %d bytes.\n", d, sizeof(d));

}
