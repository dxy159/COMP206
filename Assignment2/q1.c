#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//INITIATE ALL GLOBAL VARIABLES
char *inputDays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
char *inputMonths[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
 "Aug", "Sep", "Oct", "Nov", "Dec"};
int NUMBER_OF_WEEKDAYS = 7;
int NUMBER_OF_MONTHS = 12;

int main(int argc, char **argv) {

//GET ALL THE INFORMATION FROM STDIN
	char weekDay[10];
	char month[10];
	int day;
	char time[10];
	char edt[10];
	int year;

	scanf("%s", weekDay);
	scanf("%s", month);
	scanf("%d", &day);
	scanf("%s", time);
	scanf("%s", edt);
	scanf("%d", &year);
	
	FILE *read = NULL;
	if((read = fopen(argv[1], "r")) == NULL) {
		printf("%s\n", "Cannot read file.");
		return 1;
	}
	char token[10];
	char outputWeekday[10];
	char outputMonth[10];

//GET THE CORRESPONDING WEEKDAY AND MONTH FOR CORRECT LANGUAGE THROUGH THE FILES	
	for (int i = 0; i < NUMBER_OF_WEEKDAYS; i++) {
		fscanf(read, "%s", token);
		if (strcmp(inputDays[i], weekDay) == 0) {
			strcpy(outputWeekday, token);
		}
	}

	for (int i = 0; i < NUMBER_OF_MONTHS; i++) {
		fscanf(read, "%s", token);
		if (strcmp(inputMonths[i], month) == 0) {
			strcpy(outputMonth, token);
		}
	}

//PRINT EVERYTHING
	printf("%s %s %d %s %s %d\n", outputWeekday, outputMonth, day, time, edt, year);

	fclose(read);
	return 0;

}
