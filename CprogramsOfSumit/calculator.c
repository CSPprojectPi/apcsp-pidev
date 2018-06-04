#include <stdio.h>

float multiplication(float a, float b){

	float mulAns = 0;
	mulAns = a * b;
	return mulAns;
}

int main(){

	float mulAns1 = 0;
	char x[256];
	char y[256];
	float a;
	float b;
	
	printf("Enter the first number you want to multiply:\n");
	while (1){
		fgets(x, 256, stdin);
		if (sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}
	printf("Enter the second number: \n");
	while (1)
	{
		fgets(y, 256, stdin);
		if (sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}

	mulAns1 = multiplication(a, b);
	printf("The product of %f and %f is %f.\n", a, b, mulAns1);
}

