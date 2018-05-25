#include <stdio.h>

void arrayAdd(int array[], int addValue, int arrayLength) {

 

  for (int i = 0; i < arrayLength; i++) {
    array[i] += addValue;

    if (i != 99) {
      printf ("%d, ", array[i]);
    } else {
      printf ("%d", array[i]);
    }
  }
}

void main (void) {

  int array[100];

  for (int i = 0; i < 100; i++) {
    array[i] = i * i;
  }

  arrayAdd(array, 5, 100); 

  printf ("\n");

}
