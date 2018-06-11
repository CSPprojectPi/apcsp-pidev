#include <stdio.h>

int main(){

int a;
int* ptrtoa;

ptrtoa = &a;

a = 5; 
printf("The value of a is %d\n", a);

*ptrtoa = 6;
printf("The value of a is %d\n", a);

printf("The value of ptrtoa is %d\n", ptrtoa);
printf("It stores the value %d\n", *ptrtoa);
printf("The address of a is %d\n", a);

float d = 10;
float e = 11;
float* ptrtoD = &d;
float* ptrtoE = &e;
printf("The value of d is %f and its address is %d\n", d, &d);
printf("The value of e is %f and its address is %d\n", e, &e);

int temp = 0;
temp = *ptrtoD;
*ptrtoD = *ptrtoE;
*ptrtoE = temp;
printf("The value of e now is %f\n", *ptrtoE);
printf("The value of d now is %f\n", *ptrtoD);
}
