#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//INITIATE GLOBAL VARIABLES
int WIDTH_OF_TERMINAL = 80;
int NUMBER_OF_WEEKDAYS = 7;
int NUMBER_OF_MONTHS = 12;
int DAYS_IN_MONTH = 30;

//FUNCTION FOR PRINTING STARS ACROSS SCREEN
void printStars() {
	for (int j = 0; j < WIDTH_OF_TERMINAL; j++){
		printf("%c", '*');	
	}
	printf("\n");
}

//FUNCTION FOR PRINTING SPACES
void printSpaces(int numOfSpaces) {
	for (int i = 0; i < numOfSpaces; i++) {
		printf(" ");
	}
}

int main(int argc, char *argv[]) {

//INITIATE ARGUMENTS
	FILE *read;
	read = fopen(argv[1], "r");
	int daySize = atoi(argv[2]);
	int startDay = atoi(argv[3]);

	char weekdays[NUMBER_OF_WEEKDAYS][10];
	char months[NUMBER_OF_MONTHS][10];
	char token[10];
	
	if (read == NULL) {
		printf("%s\n", "Cannot read file.");
		return 1;
	} 

//SET WEEKDAYS AND MONTHS ACCORDING TO LANGUAGE IN FILE
	for (int i = 0; i < NUMBER_OF_WEEKDAYS; i++) {
		fscanf(read, "%s", token);		
		strcpy(weekdays[i], token);
	}	

	for (int i = 0; i < NUMBER_OF_MONTHS; i++) {
		fscanf(read, "%s", token);
		strcpy(months[i], token);
	}

//START WILL BE THE STARTING DAY
	int start = startDay;

//ITERATE THROUGH EACH MONTH
	for(int i = 0; i < NUMBER_OF_MONTHS; i++) {

		printStars();

		printf("* %s \n", months[i]);

		printStars();

//ITERATE THROUGH EACH WEEKDAY
		for (int j = 0; j < NUMBER_OF_WEEKDAYS; j++) {
			char modifiedWeekday[daySize];
			strncpy(modifiedWeekday, weekdays[j], daySize);
			modifiedWeekday[daySize] = '\0';
			printf("* %s ", modifiedWeekday);
			
			if (strlen(modifiedWeekday) < daySize) {
				int spaces = daySize - strlen(modifiedWeekday);
				printSpaces(spaces);
			}
		}
		printf("\n");

		printStars();

		for (int k = 0; k < start; k++) {
			printf("* ");
			printSpaces(daySize + 1);
		}

//ITERATE THROUGH EACH DAY OF MONTH
		for (int j = 1; j <= DAYS_IN_MONTH; j++) {

			if (((j + start - 1) % 7 == 0)) {
				printf("\n");
			}
			printf("* %d", j);

			int numOfSpaces;
			if (j >= 10) {
				numOfSpaces = (daySize+1)-2;
			} else {
				numOfSpaces = (daySize+1)-1;
			}
			printSpaces(numOfSpaces);
		}
		printf("\n");

//SET START FOR NEXT MONTH
		start = (30+start) % 7;
	}
	fclose(read);
	return 0;
}




