#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ccolors.h"
int main() {
	char command[200];
	printf(GRN "Hi, this is my well, not so awesome command line app. Commands: \"rand\" which prints a random number between 2 numbers, \"pasgen\" which is an undesired operation. \"time\" which prints the time. \"fileadd\" which adds a file.\n");
	printf(BLU "Enter the command:\n");
	scanf("%s", &command);
	if (strcmp(&command, "rand") == 0) {
		int num1;
		int num2;
		printf(YEL "%s is chosen\n", command);
		printf(BLU "What is the first number?\n");
		scanf("%d", &num1);
		printf("What is the second number? (Has to be higher than first number.)\n");
		scanf("%d", &num2);
		srand(time(0));
		int lower = num1, upper = num2;
    		printf(GRN "The random number is: ");
    		for (int i = 0; i < 1; i++) {
        		int num = (rand() % (upper - lower + 1)) + lower;
        		printf("%d \n", num);
    		}
	}

	if (strcmp(&command, "pasgen") == 0) {
		printf(RED "WARNING! UNDESIRED OPERATION!\n");
		printf(BLU "Type any 6 letter word.\n");
		char a[6];
		scanf("%s", &a);
		printf("Type any 6-digit int.\n");
		char b[6];
		scanf("%d", &b);
		char one = a[0];
		char two = a[1];
		char three = a[2];
		char four = a[3];
		char five = a[4];
		char six = a[5];
	        char seven = b[0];
		char eight = b[1];
		char nine = b[2];
		char ten = b[3];
		char eleven = b[4];
		char twelve = b[5];
		printf(GRN "Your password is %c%c%c%c%c%c%c%c%c%c%c%c\n", &four, &six, &two, &five, &one, &three, &ten, &twelve, &seven, &nine, &eleven, &eight);
		printf("Followed by %c%c%c%c%c%c\n", &six, &five, &four, &three, &two, &one);
	}

	if (strcmp(&command, "time") == 0) {
		  time_t t;   // not a primitive datatype
		  time(&t);
		  printf(RED "NOTE: THE TIME IS DISPLAYED IN HH:MM:SS\n");
		  printf(GRN "Here is the date right now: %s\n", ctime(&t));
	}

	if (strcmp(&command, "fileadd") == 0) {
			char *name[1000];
			char *ex[1000];
			char *content[1000];
			printf(MAG "What is the name of your file?\n");
			scanf("%s", &name);
			strcat(&name, ".txt");
			printf("What is the content of the file?\n");
			scanf("%s", &content);
			FILE *f_ptr;
			f_ptr = fopen(&name, "w");
			if (f_ptr == NULL) {
				printf(RED "Operation failed: could not write to file\n");
				return;
			}
			printf(GRN "Great success!\n");
			fprintf(f_ptr, &content);
			fflush(f_ptr);
			fclose(f_ptr);
	}

	if (strcmp(&command, "") == 0) {
			
	}

	printf(YEL "Bye bye!, type maa to reopen this program.\n");
}
