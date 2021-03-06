#include <stdio.h>
#include <stdlib.h>

#include <math.h>
//math.h is only used for modulus operation, nothing else.

void introduction()
{
	printf("For Multiplication, type 'x'\n");
	printf("For Division, type '/'\n");
	printf("For Subtraction, type '-'\n");
	printf("For Addition, type '+'\n");
	printf("For Modulus, type 'm'\n");
	printf("For Factorial, type '!'\n");
	printf("For clearing the screen, type 'c'\n");
	printf("For exiting, type 'e'\n");

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

	printf("\nEnter the first number you want to multiply: \n");
	while (1) {
		fgets(x, 256, stdin);
		if (sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number: ");
	}
	printf("Enter the second number: ");
	while (1) {
		fgets(y, 256, stdin);
		if (sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number: ");
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
	
	printf("\nEnter the dividend: \n");
	
	while(1){
		fgets(x, 256, stdin);
		if(sscanf(x, "%f", &c) == 1)
			break;
		else
			printf("It needs to be a number: ");
	}
	
	printf("Now enter the divisor: ");
	
	while(1){
		fgets(y, 256, stdin);
		if((sscanf(y, "%f", &d) == 1) && d != 0)
			break;
		else
			printf("It needs to be a non-zero number: ");
	}

	divAns = c/d;	
	printf("%f divided by %f is %f\n", c, d, divAns);
	printf("Enter the symbol of the math operation you want to perform: ");
}

float subtraction()
{
	float subtAns = 0;
	char x[256];
	char y[256];
	float a = 0;
	float b = 0;
	
	printf("\nEnter the first number: \n");
	
	while(1)
	{
		fgets(x, 256, stdin);
		if (sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number: ");
	}
	
	printf("Enter the second number: ");
	
	while(1)
	{
		fgets(y, 256, stdin);
		if(sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number: ");
	}
	
	subtAns = a - b;
	printf("%f minus %f is equal to %f\n", a, b, subtAns);
	printf("Enter the symbol of the math operation you want to perform: ");
}

float addition()
{
	float addAns = 0;
	char x[256];
	char y[256];
	float a = 0;
	float b = 0;
	
	printf("\nEnter the first number you want to add: \n");
	
	while(1)
	{
		fgets(x, 256, stdin);
		if(sscanf(x, "%f", &a) == 1)
			break;
		else
			printf("It needs to be a number: ");	
	}
	
	printf("Enter the second number you want to add: ");
	
	while(1)
	{
		fgets(y, 256, stdin);
		if(sscanf(y, "%f", &b) == 1)
			break;
		else
			printf("It needs to be a number: ");
	}
	addAns = a + b;
	printf("The sum of %f and %f is %f\n", a, b, addAns);
	printf("Enter the symbol of the math operation you want to perform: ");
}

float factorial()
{
	char x[256];
	float a = 0;
	float factorialAns = 0;
	int l = 1;
	
	printf("\nEnter the integer number you want to get the factorial of: \n");
	while(l)
	{
		fgets(x, 256, stdin);
		if((sscanf(x, "%f", &a) == 1) && ((a >= 1)))
			break;
		else 
			printf("It needs to be a positive number: ");
			
	 } 
	
	factorialAns = a;
	
	for(int i = 1; i < a; i++)
	{
		factorialAns = factorialAns * i;
	}
	printf("The factorial of %f is %f\n", a, factorialAns);
	printf("Enter the symbol of the math operation you want to perform: ");
	
}

/*int factorial2()
{
	int factorialAns = a;
	
	for(int i = 1; i < a; i++)
	{
		factorialAns = factorialAns * i;
	}
}
*/
float modulus()
{
	int modAns = 0;
	char x[256];
	char y[256];
	int a = 0;
	int b = 0;
	
	printf("\nEnter the dividend as an integer: \n");
	while(1)
	{
		fgets(x, 256, stdin);
		if(sscanf(x, "%d", &a) == 1)
			break;
		else
			printf("It needs to be a number: ");
	}
	printf("Enter the divisor as an integer: ");
	while(1)
	{
		fgets(y, 256, stdin);
		if((sscanf(y, "%d", &b) == 1) && b != 0)
			break;
		else
			printf("It needs to be a non-zero number: ");
	}
	
	modAns = a%b;
	printf("The modulus of %d over %d is %d\n", a, b, modAns);
	printf("Enter the symbol of the math operation you want to perform: ");
}


int main(int argc, char *argv[]) {
		
	char user_input1;	
	int user_input2;
	int user_input3;
	
	if (argc == 4)
	{
		sscanf(argv[1], "%c", &user_input1);
		sscanf(argv[2], "%d", &user_input2);
		sscanf(argv[3], "%d", &user_input3);
		
			
			switch (user_input1) {
			case 'x': printf("%d\n", user_input2 * user_input3);
					return 1;
			case '/': if(user_input3 == 0)
				   printf("undefined\n");
				else
				  printf("%d\n", user_input2/user_input3);
				return 1;
			case '-': printf("%d\n", user_input2 - user_input3);
					return 1;
			case '+': printf("%d\n", user_input2 + user_input3);
					return 1;
			case 'm':  if(user_input3 == 0)
				  printf("divisor can not be 0\n");
				else
				  printf("%d\n", user_input2%user_input3);
					return 1;
		}
		
	
	}
	else
	{
		introduction();

		int l = 1;

		while (l) {
		
			char Input = getchar();
		
			switch (Input) {
			case 'x': multiplication();
						break;
				
			case '/': division();
					break;
		
			case '-': subtraction();
					break;
			case '+': addition();
					break;
			case '!': factorial();
					break;
			case 'm': modulus();
					break;
			case 'c': system("cls");
						introduction();
						break;
			case 'e': exit(0);
						break;
			default: printf("\nEnter one of the values from above: ");
			}
    
	}
}
	}
