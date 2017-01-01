#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int MAX_NUM_OF_ITERATIONS;

void reverse_string(char *string) {
	if (string == 0 || *string == 0){
		return;
	}
	int length = strlen(string);
	char *start = string;
	char *end = start + strlen(string) -1;
	char temp;
	while (end > start){
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}

}

bool isValid(char *source, int source_len) {
	for (int i = 0; i < source_len; i++) {
		if ((!isalpha(source[i])) && (source[i] != 32)) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	FILE *read;
	read = fopen(argv[1], "r");

	char source[100];
	fscanf(read, "%s", source);

	int source_len = strlen(source);


	int count = 0;
	while (!isValid(source, source_len)) {

		for (int j = 0; j < source_len; j++) {
			source[j]--;
			if (source[j] <= 0) {
				source[j] += 256;
			}
		}
		count++;
	}
	source[source_len] = 'A';
	source[source_len + 1] = '\0';
	reverse_string(source);

	printf("%d\n", count);
	printf("%s\n", source);

	return 0;
}








