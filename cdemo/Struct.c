#include <stdio.h>
#include <string.h>

struct Student {
  char firstname[250];
  char lastname[250];
  int age;
  int studentID;
};

void print_Student (struct Student* student) {
  printf ("So you are %s", (*student).firstname);
  printf (" %s,", (*student).lastname);
  printf (" you are %d years old,", (*student).age);
  printf (" and your student ID is %d.", (*student).studentID);

}


void printStudent (struct Student* student) {
  printf ("So you are %s %s, you are %d years old and your student ID is %d", (*student).firstname, (*student).lastname, (*student).age, (*student).studentID);
}

int main () {
  char input[250];
  struct Student student1;

  printf ("firstname?...\n");
  fgets(input, 256, stdin);
  sscanf(input, "%s", student1.firstname);
  printf ("\n");

  printf ("ok, last name?...\n");
  fgets(input, 256, stdin);
  sscanf(input, "%s", student1.lastname);
  printf ("\n");

  printf ("alright, now your age?...\n");
  while (1) {
  fgets(input, 256, stdin);
  if (sscanf(input, "%d", &student1.age) == 1) {
  printf ("\nhm... alright, now what's your student ID?...\n");
  break;
  }
  printf ("har har, very funny, now answer the question seriousally, what is your age.");
  printf ("\n");
  }

  while (1) {
  fgets(input, 7, stdin);
  if (sscanf(input, "%d", &student1.studentID) == 1) {
  printStudent(&student1);
  break;
  }
  printf ("really? ok what is your student ID?\n");
  }
  printf ("\n");
}
