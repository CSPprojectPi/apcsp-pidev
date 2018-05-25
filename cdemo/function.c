#include <stdio.h>

float areaOfCircle(float r){

	float area = 0;
	area = 3.14*r*r;
	return area;
}

void main(void){

	float mainArea = 0;
	float r = 3.5;
	for(r = 3.5; r <= 12.5; r++){
		mainArea = areaOfCircle(r);
		printf("the area of the circle with r = %f is %f\n", r, mainArea);
	}
}
