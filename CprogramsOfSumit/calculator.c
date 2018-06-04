#include <stdio.h>

float multiplication(float a, float b){

	float mulAns = 0;
	mulAns = a * b;
	return mulAns;
}

float division(float c, float d){
	float divAns = 0;
	divAns = c/d;
	return divAns;
}

int main(){

	char symbol;
	
	printf("Enter the symbol of the math operation you want to perform:\n");
	printf("For Multiplication, type '*'\n");
	printf("For Division, type '/'\n");
	fgets(symbol, 1, stdin);
	sscanf(symbol, "%c", &symbol); //need to include loop for making sure the user enters only one of the symbols displayed above
	
	if(symbol = *){
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
}

