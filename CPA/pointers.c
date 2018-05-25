#include <stdio.h>

void printresults();

int switchvalues (int a, int b) {

  int temp;
  int* pointerA = &a;
  int* pointerB = &b;

  temp = *pointerA;
  *pointerA = *pointerB;
  *pointerB = temp;

  printresults(a, b);

}

int main()
{
  
  int a;
  int* ptrtoa;
  int d;
  int e;

  d = 7;
  e = 10;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printresults(d, e);

  printf("The value of ptrtoa is %d\n", ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %d\n", &a);

  switchvalues (d, e);
}

void printresults(int a, int b) {

  int* pointerA = &a;
  int* pointerB = &b;

  printf ("the value d (which equals to %d) has adress %d\n", *pointerA, pointerA);
  printf ("the value e (which equals to %d) has adress %d\n", *pointerB, pointerB);

}
