//Grant Haataja
//Assignment 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	//define buffer array
	char buffer[256];
	//string variable to hold each individual line
	char *line = NULL;
	size_t length;
	FILE *stream;
	//display buffer address
	printf("Buffer Address: %p\n\n",buffer);
	//check if file is valid	
	if ((stream = fopen("hw10.data", "r")) == NULL) {
		printf("\nFile not found...\n");
		return 0;
	}
	//read in data from file
	getline(&line, &length, stream);
	//display file contents
	printf("File Contents: <%s>\n\n",line);
	//close file
	fclose(stream);
	//copy data from file into buffer
	strncpy(buffer, line, 256);
	//destroy the evidence
	free(line);
	//display buffer contents
	printf("Buffer Contents: <%s>\n",buffer);

	return 0;
}
