#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>




//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Tile struct-=-=-=-=-=-=-=
struct Tile {
  long int x;
  long int y;
  long int z;
  int time;
  int tileType;
  /*
  1: chest
  2: campfire
  3: fire
  4: trap
  5: enemy
  6: prey
  7: furnace
  */
  int tileEnviroment;
  /*
  1: vegitation
  2: river
  3: empty
  */
  int items[21];
  /*
  -tree height
  -stones
  -bush height
  -clay
  -meat
  -wooden ax
  -wooden arrows
  -bow
  -empty bottle
  -club
  -torch", "stone ax", "stone arrows", "string", "planks", "sticks", "cooked meat", "water bottles", "berry juice"
  */
};

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-User input-=-=-=-=-=-=-=-
char SetInputTo (char input[], int n) {
fgets(input, n, stdin);
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-The start-=-=-=-=-=-=-=-=
int Start () {
  char input[256];
  long int size;
  char Startsign[] = "===============================\n Welcome To Survial Island!!!\n\n          type start\n===============================\n";
  char buffer[256];

  printf ("%s",Startsign);
  while (1) {
    SetInputTo(buffer, 256);
    if (sscanf(buffer, "%s", input) == 1) {
        if (strcmp(input, "start") == 0) {
          printf ("\nthe adventure begins\n\n");
          break;
        } 
        printf ("please type start\n");
    } else {
        printf ("please type start\n");
    }
  }

  printf ("=========================================\n          on a scale of 1 to 10 \n how large would you like your island?\n=========================================\n");
  while (1) {
    SetInputTo(buffer, 256);
    if (sscanf(buffer, "%ld", &size) == 1) {
        if (size < 11 && size > 0) {
          printf ("creating island...\n");
          size *= 10;
          size *= size;
          return size;
        } 
        printf ("please put in a valid number\n");
    } else {
      printf ("please put in a valid number\n");
    }
  }
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-is word-=-=-=-=-=-=-=-=-=
int isWord(char input[]) {
  for (int i = 0; i < strlen(input); i++) {
    if (!( isalpha(input[i]) || isspace(input[i]))){
      return 0;
    }
    return 1;
  }
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-seed generator-=-=-=-=-=-
int SeedGenerator () {
  char name[256];
  int date = 0;
  int birthday = 0;
  char buffer[256];
  int result;
  
  while (1) {

    while (1) {
      printf ("====================\n what is your name?\n====================\n");
      SetInputTo(buffer, 256);
      if (isWord(buffer)) break;
      printf ("please put in a name.\n\n");
    }

    if (date == 0) {
      while (1) {
        printf ("========================================================\n what is the date today? (ex. 05252013 is may 25, 2013)\n========================================================\n");
        SetInputTo(buffer, 8);
        if (sscanf(buffer, "%d", &date)) break;
        printf ("please put in the date.\n\n");
      }
    }

    if (birthday == 0) {
      while (1) {
        printf ("=============================================================\n what is your birthday today? (ex. 05252013 is may 25, 2013)\n=============================================================\n");
        SetInputTo(buffer, 8);
        if (sscanf(buffer, "%d", &birthday)) {
          break;
        }
      printf ("please put in the date.\n\n");
      }
    }

    if (!(date == 0 || birthday == 0)) {
      break;
    }
  }

  for (int i = 0; i < 255; i++) {
    result += name[i];
    result += date;
    result += birthday;
    result++;
    printf ("%d\n", result);
  }
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Main-=-=-=-=-=-=-=-=-=-=-
void main () {
  /*for (int i = 0; i < 10; i++){
    printf("%f\n", perlin(0.3f, 0.2f));
  }*/

  long int NumberOfTiles = Start();
  struct Tile tiles[NumberOfTiles];
  //int startvalue = SeedGenerator();
  int x = 0;
  int y = 0;
  int health = 100;
  int hunger = 100;
  int hydration = 100;
  int direction = 0;
  int elevation = 0;
  int time = 0;
  int minuits = 0;
  int hours = 0;
  int days = 0;
  char buffer[256];
  char input[256];
  int frame = 0;
  int actionsPerFrame = 0;
  int items[20] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
  char itemNames[20][18] = {"leaves", "wood", "stones", "meat", "berries", "clay", "wooden ax", "wooden arrows", "bow", "empty bottle", "club", "torch", "stone ax", "stone arrows", "string", "planks", "sticks", "cooked meat", "water bottles", "berry juice"};

  int i = 0;
  int xyz = ((long int)(sqrt(NumberOfTiles))/2);
  for (long int x = -xyz; x != xyz; x++) {
    for (long int y = -xyz; y != xyz; y++) {
      i++;
      (tiles[i]).x = x;
      (tiles[i]).y = y;
      (tiles[i]).tileEnviroment = 3;
      //printf ("Tile %d: (%d, %d)\n", i, (tiles[i]).x, (tiles[i]).y);
    }
  }

  printf ("finished: %ld tiles\n\n", NumberOfTiles);
  //printf ("generating enviroment...\n");

  while (1) {
    minuits = time%60;
    hours = (time%60)%24;
    days = (time / 1440) + 1;
    if (health > 100) {
      health = 100;
    }
    if (hunger > 100) {
      hunger = 100;
    }
    if (hydration > 100) {
      hydration = 100;
    }
    
    printf ("\n[Enviroment]:");
      if (time == 0) {
        printf ("You just woke up from sleeping, you have no idea of who you are, where you are, not even what you are... but you know... you must survive, you must sruvive to get out of this place... maybe you should try to find others like you, if that's even possible... welp it's up to you what you want to do, and you know that...");
      } /*else if (they discover they are on an island) {

      } else if (they find out there are no other people) {

      } else {
        if (there are trees to your left) {
          
        }
        if (there are trees infront) {

        }
        if (there are trees to your right) {

        }
        if (there are tree behind you) {

        }
      }*/
    printf ("\n===============================\nwhat would you like to do?: (time:%d:%d day:%d)\n  health[%d] hunger[%d] hydration[%d%] \n  latitude[%d] longitude[%d] elevation[%d]\n -items\n -run\n -eat\n -make\n -sleep\n -interact \n(exit)\n===============================\n\n", hours, minuits, days, health, hunger, hydration, x, y, elevation);
    SetInputTo(buffer, 256);
    if (sscanf(buffer, "%s", input) == 1) {
        if (strcmp(input, "items") == 0) {
          printf ("\nItems:\n");
          int totalItems = 0;
          for (int i = 0; i < 20; i++){
            if (items[i] != 0) {
              printf ("%s: %d\n", itemNames[i], items[i]);
              totalItems++;
            }
          }
          if (totalItems == 0){
            printf ("empty\n");
          }
          printf ("\n");
        } else if (strcmp(input, "run") == 0) {
          while (1) {
            printf ("\n==========================================================================\n where would you like to run? (ex. 4 5 = 4 tiles forward 5 tiles right)\n (exit)\n==========================================================================\n\n");
            SetInputTo(buffer, 256);
            int addx = 0;
            int addy = 0;

            if (sscanf(buffer, "%d %d", &addx, &addy) == 2) {
              x += addx;
             // direction += 2 * addx/abs(addx);
              y += addy;
              //direction += addy/abs(addy);
             // direction = (direction)
              printf ("\n");
              break;
            }
            if (sscanf(buffer, "%s", input) == 1) {
              if (strcmp(input, "exit") == 0) {
                break;
              }
            }

            printf ("\nput in valid coordinates...\n");
          }
        } else if (strcmp(input, "eat") == 0) {
          while (1) {
            printf ("\n==================================");
            printf ("\nwhat do you want to eat/drink?:\n");
            for (int i = 3; i != 5; i++ ) {
              if (items[i] > 0) {
                printf (" -%s\n", itemNames[i]);
              }
            }
            for (int i = 17; i != 20; i++ ) {
              if (items[i] > 0) {
                printf (" -%s\n", itemNames[i]);
              }
            }
            printf ("(exit)\n");
            printf ("==================================\n");
            SetInputTo(buffer, 256);
            char foodbuffer[256];
            char foodbufferer[256];

            if (sscanf(buffer, "%s", foodbuffer) == 1) {
              if (strcmp(foodbuffer, "meat") == 0 && items[3] != 0) {
                hunger += 15;
                items[3]--;
                printf ("uggg... raw...\n");
                break;
              }
              if (strcmp(foodbuffer, "berries") == 0 && items[4] != 0) {
                hunger += 5;
                //hydration += ;
                items[4]--;
                printf ("sower yet juicy...\n");
                break;
              }
              if (strcmp(foodbuffer, "exit") == 0) {
                printf ("\n");
                break;
              }
            } 
            if (sscanf(buffer, "%s %s", foodbuffer, foodbufferer) == 2) {
              //printf ("%s %s", foodbuffer, foodbufferer);
              if (strcmp(foodbuffer, "cooked") == 0 && strcmp(foodbufferer, "meat") == 0 && items[17] != 0) {
                hunger += 50;
                items[17]--;
                printf ("\nmhm that hit the spot...\n");
                break;
              }
              if (strcmp(foodbuffer, "water") == 0 && strcmp(foodbufferer, "bottle") == 0 && items[18] != 0) {
                //hydration += ;
                items[18]--;
                items[9] += 1;
                printf ("\n(*gulp) phiew, nice and cool...\n");
                break;
              }
              if (strcmp(foodbuffer, "berry") == 0 && strcmp(foodbufferer, "juice") == 0 && items[19] != 0) {
                hunger += 30;
                //hydration += ;
                items[19]--;
                items[9] += 1;
                printf ("\ntasts like a smothie...\n");
                break;
              }
            }
            printf ("\nchoose something you have (don't be picky)...\n");
          }
        } else if (strcmp(input, "make") == 0) {
          while (1){
            printf ("============================================\n");
            printf ("what do you want to make?:\n");
            printf ("\n~stone ax (%d/1 string, %d/1 stone, %d/1 stick)\n", items[14], items[2], items[16]);
            printf ("\n~wood ax (%d/1 string, %d/1 plank, %d/1 stick)\n", items[14], items[15], items[16]);
            printf ("\n~furnace (%d/20 clay, %d/10 stones)\n", items[5], items[2]);
            printf ("\n~empty bottle (%d/1 wood)\n", items[1]);
            printf ("\n~berry juice (%d/5 berries, %d/1 water bottle, %d/1 stick)\n", items[4], items[18], items[16]);
            printf ("\n~planks x 4 (%d/2 wood)\n", items[1]);
            printf ("\n~bow (%d/1 stick, %d/2 string)\n", items[16], items[14]);
            printf ("\n~wooden arrow (%d/3 leaves, %d/1 stick)\n", items[0], items[16]);
            printf ("\n~stone arrow (%d/3 leaves, %d/1 stick, %d/1 clay, %d/1 stone)\n", items[0], items[16], items[5], items[2]);
            printf ("\n~string (%d/2 leaves)\n", items[0]);
            printf ("\n~sticks x 5 (%d/1 wood)\n", items[1]);
            printf ("\n~club (%d/2 sticks)\n", items[16]);
            printf ("(exit)\n");
            printf ("============================================\n");


            SetInputTo(buffer, 256);
            char makebuffer[256];
            char makebufferer[256];
            int error = 0;

            if (sscanf(buffer, "%s", makebuffer) == 1) {
              if (strcmp(makebuffer, "furnace") == 0 ) {
                if (items[5] >= 20 && items[2] >= 10) {
                items[5] -= 20;
                items[2] -= 10;
                //set tile to furnace
                printf ("made a furnace!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "planks") == 0) {
                if (items[1] >= 2) {
                  items[1] -= 2;
                  items[15] += 4;
                  printf ("make 4 planks!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "bow") == 0) {
                if (items[16] >= 1 && items[14] >= 2) {
                  items[16] -= 1;
                  items[14] -= 2;
                  items[8] += 1;
                  printf ("made a bow!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "string") == 0) {
                if(items[0] >= 2) {
                  items[0] -= 2;
                  items[14] += 1;
                  printf ("made string!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "sticks") == 0) {
                if (items[1] >= 1) {
                  items[1] -= 1;
                  items[16] += 5;
                  printf ("made 5 sticks!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "club") == 0) {
                if (items[16] >= 2) {
                  items[16] -= 2;
                  items[10] += 1;
                  printf ("made a club!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "exit") == 0) {
                printf ("\n");
                break;
              } else {
                error++;
              }
            } 
            if (sscanf(buffer, "%s %s", makebuffer, makebufferer) == 2) {
              error--;
              if (strcmp(makebuffer, "stone") == 0 && strcmp(makebufferer, "ax") == 0) {
                if (items[2] >= 1 && items[14] >= 1 && items[16] >= 1) {
                  items[2] -= 1;
                  items[14] -= 1;
                  items[16] -= 1;
                  items[12] += 1;
                  printf ("made a stone ax!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "wood") == 0 && strcmp(makebufferer, "ax") == 0) {
                if (items[14] >= 1 && items[15] >= 1 && items[16] >= 1) {
                  items[14] -= 1;
                  items[15] -= 1;
                  items[16] -= 1;
                  items[6] += 1;
                  printf ("made a wood ax!...\n\n");
                } else {
                    printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "empty") == 0 && strcmp(makebufferer, "bottle") == 0) {
                if (items[1] >= 1) {
                  items[1] -= 1;
                  items[9] += 1;
                  printf ("made a empty bottle!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "berry") == 0 && strcmp(makebufferer, "juice") == 0) {
                if (items[4] >= 5 && items[18] >= 1 && items[16] >= 1) {
                  items[4] -= 5;
                  items[18] -= 1;
                  items[19] += 1;
                  printf ("made some berry juice!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "wooden") == 0 && strcmp(makebufferer, "arrow") == 0) {
                if (items[0] >= 3 && items[16] >= 1) {
                  items[0] -= 3;
                  items[16] -= 1;
                  items[7] += 1;
                  printf ("made a wooden arrow!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (strcmp(makebuffer, "stone") == 0 && strcmp(makebufferer, "arrow") == 0) {
                if (items[0] >= 3 && items[16] >= 1 && items[5] >= 1 && items[2] >= 1) {
                  items[0] -= 3;
                  items[16] -= 1;
                  items[5] -= 1;
                  items[2] -= 1;
                  items[13] += 1;
                  printf ("made a stone arrow!...\n\n");
                } else {
                  printf ("not enough material!...\n");
                }
              } else if (error != 1) {
                error++;
              }
            }
            if (error > 0) {
              printf ("please put a valid input!...\n");
            }
          }
        //add more recipies to the make function
        } else if (strcmp(input, "sleep") == 0) {
          printf ("sleep\n");
        } else if (strcmp(input, "interact") == 0) {
          if (items[9] > 0 && items[13] > 0 || items[9] > 0 && items[7]) {
            int longrangetilenumbers[40];
            int shortrangetilenumbers[9];
            int longposition = 0;
            int shortposition = 0;

            printf ("\n==========================\n");
            for (int i = 0; i < NumberOfTiles; i++) {
              for (int xa = -3; xa != 4; xa++) {
                for (int ya = -3; ya != 4; ya++) {
                  if ((tiles[i]).x == (x + xa) && xa > -2 && xa < 2) {
                    if ((tiles[i]).y == (y + ya) && ya > -2 && ya < 2) {
                      longrangetilenumbers[longposition] = i;
                      longposition++;
                    }
                  } else if ((tiles[i]).x == (x + xa)) {
                    if ((tiles[i]).y == (y + ya) && ya < -2 && ya > 2) {
                      shortrangetilenumbers[shortposition] = i;
                      shortposition++;
                    }
                  }
                }
              }
            }
            printf ("\n==========================\n");

            while (1) {

              break;
            }

          } else {
            printf ("\n==========================\n");
            int tilenumbers[9];
            int position = 0;
            for (int i = 0; i < NumberOfTiles; i++) {
              for (int xa = -1; xa != 2; xa++) {
                for (int ya = -1; ya != 2; ya++) {
                  if ((tiles[i]).x == (x + xa)) {
                    if ((tiles[i]).y == (y + ya)) {
                      tilenumbers[position] = i;
                      position++;
                    }
                  }
                }
              }
            }
            printf ("\n==========================\n");

            while (1) {

              break;
            }

          }
        } else if (strcmp(input, "exit") == 0) {
          break;
        } else {
          printf ("\nplease put in a valid command\n\n");
        }
    } else {
        printf ("please type a comand\n");
    }

  }

}
