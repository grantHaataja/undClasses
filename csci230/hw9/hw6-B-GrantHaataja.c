//Grant Haataja
//Assignment 9: LOAD Function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
struct _data {                                 
	char *name;
	long number;
};

//function to create a dynamic array of length 'size' and store data in struct
struct _data *LOAD(FILE *stream, int size, char *fileName) {
	//hold each individual line of file
	char *line = NULL;
	size_t length = 0;
	//string variable to hold name from each line and copy it to BlackBox
	char *first;
	//string variable to hold number from each line and convert it to long
	char *second;
	//declare structure BlackBox
	struct _data *BlackBox;
	//allocate memory for structure equal to number of lines in file
	BlackBox = (struct _data*) calloc(size, sizeof(struct _data));
	//rewind stream to start at the beginning of file
	rewind(stream);
	for (int i = 0; i < size; i++) {
		//scan in each line of the file individually 
		getline(&line, &length, stream);
		//use deliminator to get the name from the line and assign to 'first'
		first = strtok(line, " ,\n");
		//allocate memory for each name in the struct
		BlackBox[i].name = (char*) calloc(strlen(first), sizeof(char));
		//copy each name into the struct
		strncpy(BlackBox[i].name, first, (int) strlen(first));
		//use deliminator to get the number from the line and assign to 'second'
		second = strtok(NULL, " ");
		//convert string to long and store in struct
		BlackBox[i].number = atol(second);
	}
	return BlackBox;
}
