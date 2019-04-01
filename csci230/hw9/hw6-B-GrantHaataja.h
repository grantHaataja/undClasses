//Grant Haataja
//Assignment 9: LOAD Header

#include <stdio.h>
#include <stdlib.h>

/*//Structure
struct _data {                                 
	char *name;
	long number;
};*/

//function to create a dynamic array of length 'size' and store data in struct
struct _data *LOAD(FILE *stream, int size, char *fileName);
