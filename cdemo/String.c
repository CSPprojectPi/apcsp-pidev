#include <stdio.h>
#include <string.h>

void main() {
  char alphbet1[27];
  char alphbet2[] = "abcdefghijklmnopqrstuvwxyz";
  char alphbet3[27];
  char alphbet4[27];


  printf ("alphbet 1: %s\n", alphbet2);
  char c = 'a';

  printf ("alphbet 2: ");
  for (int i = 0; i < 26; i++) {
    alphbet1[i] = c;
    c++;
  }
  alphbet1[26] = '\0';
  printf ("alphbet 1 = %s\n", alphbet1);

  if (strcmp(alphbet1, alphbet2) == 0) {
  printf ("alphbet1 and alphbet2 are the same\n");
  } else {
  printf ("alphbet1 and alphbet2 are not the same\n");
  }

  char d = 'A';

  printf ("uppercase alphbet: ");
  for (int i = 0; i < 26; i++) {
    alphbet3[i] = d;
    d++;
  }

  alphbet3[26] = '\0';
  printf("%s", alphbet3);
  printf ("\n");

  strcat(alphbet4, alphbet1);
  strcat(alphbet4, alphbet3);
  printf("combined: %s", alphbet4);
}
