//Grant Haataja
//Assignment 9: SCAN Function

#include <stdio.h>
#include <stdlib.h>

//function to open the file/stream and count how many lines it contains
int SCAN(char *fileName, FILE *(*stream)) {
	//variable for number of lines
	int size = 0;
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	ssize_t read = 0;
	//check if file is valid
	if ((*stream = fopen(fileName, "r")) == NULL) {
		printf("\nFile not found...\n");
		free(fileName);
		return 0;
	}
	else {
		while ((read = getline(&line, &length, *stream)) != -1) {
			//increment size to count number of lines
			size++;
		}
		//free dynamically allocated line variable and return number of lines
		free(line);
		return size;
	}
}
