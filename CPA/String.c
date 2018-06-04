#include <stdio.h>
#include <string.h>

void main() {
  char alphbet1[27];
  char alphbet2[] = "abcdefghijklmnopqrstuvwxyz";
  char alphbet3[27];

  printf ("alphbet 1: %s\n", alphbet2);
  alphbet1[0] = 'a';

  printf ("alphbet 2: ");
  printf ("%c", alphbet1[0]);
  for (int i = 1; i < 26; i++) {
    alphbet1[i] = alphbet1[i-1] + 1;
    printf ("%c", alphbet1[i]);
  }
  alphbet1[26] = '\0';
  printf ("\n");

  if (strcmp(alphbet1, alphbet2) == 0) {
  printf ("alphbet1 and alphbet2 are the same\n");
  } else {
  printf ("alphbet1 and alphbet2 are not the same\n");
  }

  printf ("uppercase alphbet: ");
  for (int i = 0; i < 26; i++) {
    alphbet3[i] = alphbet1[i] - 32;
    printf ("%c", alphbet3[i]);
  }
  alphbet3[26] = '\0';
  printf ("\n");

}
