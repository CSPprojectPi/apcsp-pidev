#include <stdio.h>
#include <stdlib.h>

void introduction()
{
	printf("For Multiplication, type '*'\n");
	printf("For Division, type '/'\n\n");

	printf("Enter the symbol of the math operation you want to perform: ");
}

/* float multiply(float a, float b) {
	float mulAns = 0;
	mulAns = a * b;
	return mulAns;
}
*/
void multiplication() {
	float mulAns1 = 0;
	char x[256];
	char y[256];
	float a;
	float b;

	printf("\nEnter the first number you want to multiply:\n");
	while (1) {
		fgets(x, 256, stdin);
		if (sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}
	printf("Enter the second number: \n");
	while (1) {
		fgets(y, 256, stdin);
		if (sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}

	mulAns1 = a * b;
		
	printf("The product of %f and %f is %f.\n", a, b, mulAns1);
}

float division() {
	
	float divAns = 0;
	char x[256];
	char y[256];
	float c = 0;
	float d = 0;
	
	printf("\nEnter the dividend: \n");
	fgets(x, 256, stdin);
	while(1){
	if(sscanf(x, "%f", &c) == 1)
		break;
	else
		printf("It needs to be a number!\n");
	}
	printf("/nEnter");
	
	
	
}

int main() {

	introduction();

	int l = 1;

	while (l) {
		
		char userInput = getche();
		
		switch (userInput) {
		case '*': multiplication();
					break;
			
		case '/': division();
					break;
		}
    
	}
}
