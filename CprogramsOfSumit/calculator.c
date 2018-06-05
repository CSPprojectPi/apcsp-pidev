#include <stdio.h>
#include <stdlib.h>

void introduction()
{
	printf("For Multiplication, type '*'\n");
	printf("For Division, type '/'\n");
	printf("For subtraction, type '-'\n");
	printf("For Addition, type '+'\n");

	printf("\nEnter the symbol of the math operation you want to perform: ");
}

/* float multiply(float a, float b) {
	float mulAns = 0;
	mulAns = a * b;
	return mulAns;
}
*/
void multiplication()
{
	float mulAns1 = 0;
	char x[256];
	char y[256];
	float a;
	float b;

	printf("\nEnter the first number you want to multiply: ");
	while (1) {
		fgets(x, 256, stdin);
		if (sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("\nIt needs to be a number!\n");
	}
	printf("Enter the second number: ");
	while (1) {
		fgets(y, 256, stdin);
		if (sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("\nIt needs to be a number!\n");
	}

	mulAns1 = a * b;
		
	printf("The product of %f and %f is %f.\n", a, b, mulAns1);
	printf("Enter the symbol of the math operation you want to perform: ");
}

float division() 
{
	
	float divAns = 0;
	char x[256];
	char y[256];
	float c = 0;
	float d = 0;
	
	printf("\nEnter the dividend: ");
	
	while(1){
		fgets(x, 256, stdin);
		if(sscanf(x, "%f", &c) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}
	
	printf("Now enter the divisor: ");
	
	while(1){
		fgets(y, 256, stdin);
		if(sscanf(y, "%f", &d) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}

	divAns = c/d;	
	printf("%f divided by %f is %f/n", c, d, divAns);
	printf("Enter the symbol of the math operation you want to perform: ");
}

float subtraction()
{
	float subtAns = 0;
	char x[256];
	char y[256];
	float a = 0;
	float b = 0;
	
	printf("\nEnter the first number: ");
	
	while(1)
	{
		fgets(x, 256, stdin);
		if (sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}
	
	printf("\nEnter the second number: ");
	
	while(1)
	{
		fgets(y, 256, stdin);
		if(sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}
	
	subtAns = a - b;
	printf("%f minus %f is equal to %f", a, b, subtAns);
	printf("\nEnter the symbol of the math operation you want to perform: ");
}

float addition()
{
	float addAns = 0;
	char x[256];
	char y[256];
	float a = 0;
	float b = 0;
	
	printf("\nEnter the first number you want to add: ");
	
	while(1)
	{
		fgets(x, 256, stdin);
		if(sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number!\n");	
	}
	
	printf("\n Enter the second number you want to add: ");
	
	while(1)
	{
		fgets(y, 256, stdin);
		if(sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number!\n");
	}
	addAns = a + b;
	printf("The sum of %f and %f is %f", a, b, addAns);
}

float factorial()
{
	
}

float modulus()
{
	
}


int main() {

	introduction();

	int l = 1;

	while (l) {
		
		int userInput = getche();
		
		switch (userInput) {
		case '*': multiplication();
					break;
			
		case '/': division();
					break;
		
		case '-': subtraction();
					break;
		case '+': addition();
					break;
		case '!': factorial();
					break;
		case '%': modulus();
					break;
		case 'c': system("cls");
						introduction();
						break;
		case 'q': exit(0);
						break;
		default: printf("Enter one of the values from above");
		}
    
	}
}
