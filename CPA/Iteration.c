#include <stdio.h>

void main (void) {

int div = 3;
for (int i = 1; i <= 100; i++) {
if ((i % div) == 0) {
printf("%d evenly divides into %d.\n", i, div);

}

}

}
