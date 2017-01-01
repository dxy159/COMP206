#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void encrypt( unsigned char *source, int source_len, int key );

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

int main(int argc, char *argv[])
{
	int key = atoi(argv[1]);
	FILE *read;
	read = fopen(argv[2], "r");

	char source[100];
	fscanf(read, "%s", source);

	int source_len = strlen(source);

	encrypt(source, source_len, key);
	reverse_string(source);

	printf("%s\n", source);

	return 0;
}

void encrypt(unsigned char *source, int source_len, int key) {

	for (int i = 0; i < source_len; i++) {
		source[i] = source[i] - key;
		if (source[i] <= 0) {
			source[i] += 256;
		}
	}

}
