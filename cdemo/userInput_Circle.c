#include <stdio.h>

float areaOfCircle(float radius1){

	float area = 0;
	area = 3.14*radius1*radius1;
	return area;
}

void main(void){

	float mainArea = 0;
	char r1[256];
	char r2[256];
	float radius1;
	float radius2;

	printf("Enter the first value of the radius\n");

	while (1)
	{
		fgets(r1, 256, stdin);
		if (sscanf(r1, "%f", &radius1) == 1)
			break;
		else
			printf("Enter a NUMBER:)\n");
	}

	printf("Enter the second value of the radius\n");

	while(1)
  	{
  	  fgets(r2, 256, stdin);
  	  if (sscanf(r2, "%f", &radius2))
      		break;
    	  else
  	    printf("Enter a NUMBER:)\n");
  	}
	//fgets(r2, 256, stdin);
	//sscanf(r2, "%f", &radius2);

	for(radius1; radius1 <= radius2; radius1++)
	{
		mainArea = areaOfCircle(radius1);
		printf("the area of the circle with r = %f is %f\n", radius1, mainArea);
	}
}
