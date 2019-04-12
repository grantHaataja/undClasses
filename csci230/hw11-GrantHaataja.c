//Grant Haataja
//Assignment 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to count lines in file
int countLines(char *fileName, FILE *(*stream)) {
	//variable for number of lines
	int size = 0;
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//check if file is valid
	if ((*stream = fopen(fileName, "r")) == NULL) {
		printf("\nFile not found...\n");
		return 0;
	}
	else {
		while ((getline(&line, &length, *stream)) != -1) {
			//increment size to count number of lines
			size++;
			//free line variable and set to null
			free(line);
			line = NULL;
		}
		//return number of lines
		return size;
	}
}

//function to populate linked


//Main Routine
int main(void) {
	//define fileName
	char *fileName = "hw111.data";
	FILE *stream;
	int size = 0;
	
	//count how many lines in file
	size = countLines(fileName, &stream);
	printf("There are %d lines in file\n",size);


}
