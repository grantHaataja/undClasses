//Grant Haataja
//Assignment 6: FREE Function

#include <stdio.h>
#include <stdlib.h>

//Structure
struct _data {                                 
	char *name;
	long number;
};

//function to free all dynamic memory allocated in this program
void FREE(struct _data *BlackBox, int size, char *fileName) {
	//loop through BlackBox and free each dynamically-allocated name
	for (int i = 0; i < size; i++) {
		free(BlackBox[i].name);
	}
	//free number of listings in BlackBox
	free(BlackBox);
	//free user-entered file name
	free(fileName);
}
