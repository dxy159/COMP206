#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	
	FILE *incoming_file;
	incoming_file = fopen(argv[1], "r");
	FILE *outgoing_file;
	outgoing_file = fopen(argv[2], "w");
	char *chat_username = argv[3];
	bool flag = false;

	while (1) {
		char content[100];
		char output[100];
		//fscanf(incoming_file, "%[^\n]", content);

		fseek(outgoing_file, 0, SEEK_END);
		int outgoing_size = ftell(outgoing_file);
		fseek(incoming_file, 0, SEEK_END);
		int incoming_size = ftell(incoming_file);

		if (incoming_size != 0) {
			flag = true;
		}

		if ((outgoing_size == 0) && (incoming_size == 0) && (!flag)) {
			printf("%s\n", "Nothing recieved yet.");
			printf("Send:\t");
			fgets(output, 100, stdin);
			char real_output[100] = "[";
			strcat(real_output, chat_username);
			strcat(real_output, "] ");
			strcat(real_output, output);
			strcat(real_output, "\n");

			fputs(real_output, outgoing_file);
			flag = true;
		} 
		if ((outgoing_size == 0) && (incoming_size != 0)) {
			incoming_file = fopen(argv[1], "r");
			fscanf(incoming_file, "%[^\n]", content);
			printf("Recieved: %s\n", content);
			printf("Send:\t");
			fgets(output, 100, stdin);
			char real_output[100] = "[";
			strcat(real_output, chat_username);
			strcat(real_output, "] ");
			strcat(real_output, output);
			strcat(real_output, "\n");

			fputs(real_output, outgoing_file);
	        } 

		if (incoming_size != 0) {
			incoming_file = fopen(argv[1], "w+");
	        }

	}

	return 0;
}
