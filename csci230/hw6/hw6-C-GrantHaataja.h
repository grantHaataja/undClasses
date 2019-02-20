//Grant Haataja
//Assignment 6: SEARCH Header

#include <stdio.h>
#include <stdlib.h>

//Structure
struct _data {                                 
	char *name;
	long number;
};

//function to find the name we are searching for 
void SEARCH(struct _data *BlackBox, char *name, int size);
