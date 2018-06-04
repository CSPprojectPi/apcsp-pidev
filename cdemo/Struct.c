#include <stdio.h>
#include <string.h>

struct Student {
  char firstname[250];
  char lastname[250];
  int age;
  int studentID;
};

void printStudent (struct Student* student) {
  printf ("So you are %s %s, you are %d years old and your student ID is %d\n", (*student).firstname, (*student).lastname, (*student).age, (*student).studentID);
}

void printlist (struct Student student[], int n) {
  for (int i = 0; i < n; i++) {
    if (!(strcmp(student[i].firstname, ""))) {
      printf ("%d. %s %s\n", (i+1), (student[i]).lastname, (student[i]).firstname);
    } else {
      printf ("%d.\n", (i+1));
    }
  }
}

void getstudentinfo (struct Student* student) {
  char input[250];

  char answer[3];

  while (1) {
    printf ("firstname?...\n");
    fgets(input, 256, stdin);

    sscanf(input, "%s", student->firstname);
    printf ("\n");
    printf ("ok, last name?...\n");
    fgets(input, 256, stdin);
    sscanf(input, "%s", student->lastname);
    printf ("\n");

    printf ("alright, now your age?...\n");

    while (1) {
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", &student->age) == 1) {
        printf ("\nhm... alright, now what's your student ID?...\n");
        break;
      }
      printf ("har har, very funny, now answer the question seriousally, what is your age.");
      printf ("\n");
    }

    while (1) {
      fgets(input, 7, stdin);
      if (sscanf(input, "%d", &student->studentID) == 1) {
        printStudent(student);
        break;
      }
      printf ("really? ok what is your student ID?\n");
    }

    while (1) {
      printf ("Correct? (yes/no)");
      fgets(input, 7, stdin);
      if (sscanf(input, "%s", answer) == 1 && answer == "yes") {
        break;
      }
      printf ("\n");
    }
  }
}

int howmany () {
  char input[250];
  int n;

  printf ("how many students do you need to record?:");
  while (1) {
  fgets(input, 5, stdin);
    if (sscanf(input , "%d", &n) == 1) {
      printf ("\nstudents:\n");
      for (int i = 0; i < n; i++ ) {
        printf ("%d.\n", (i+1));
      }
      return n;
      break;
    }
  printf ("please enter the amount of students you need to record...:");
  }
}

void main () {
  char input[250];
  int n;
  int totalstudents = howmany();
  struct Student students[totalstudents];


  printf ("what would you like to do? (edit/exit)\n");
  while (1) {
    fgets(input, 4, stdin);
    if (sscanf(input , "%s", input) == 1 && strcmp(input,"edit")) {
      printf ("which student would you like to edit?:");
      while (1) {
        fgets(input, 5, stdin);
        if (sscanf(input , "%d", n) == 1 && n <= totalstudents) {
          getstudentinfo(&students[n]);
          printlist (students, n);
	  break;
        }
        printf ("that is not a valid student number\n");
      }
    }
    if (sscanf(input , "%s", input) == 1 && strcmp(input,"exit")) {
      break;
    }
    printf ("please choose a valid option\n");
  }
}

