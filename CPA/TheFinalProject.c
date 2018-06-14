#include <stdio.h>
#include <string.h>

struct Tile {
   int x;
   int y;
   int z;
   int material[4];
/*
-trees
-stones
-leaves
-fruit
*/
   int booleans[5];
/*
-barrier
-entrence
-trap
-enemy
-prey
*/
};

char SetInputTo (char input[], int n) {
fgets(input, n, stdin);
}

int Start (void) {
   char input[256];
   int size;
   char Startsign[] = "===============================\n Welcome To Survivle Island!!!\n\n          type start\n===============================\n";
   char buffer[6];


   printf ("%s",Startsign);
   while (1) {
      SetInputTo(buffer, 5);
      if (sscanf(buffer, "%s", input) == 1) {
         if (strcmp(input, "start") == 1) {
            printf ("the adventure begins\n");
            break;
         } else {
            printf ("please type start\n");
         }
      } else {
         printf ("please type start\n");
      }
   }
   return 0;
}

void main (void) {

   struct Tile tiles[Start()];

}
