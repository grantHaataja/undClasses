//Grant Haataja
//Assignment 6: SEARCH Function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
struct _data {                                 
	char *name;
	long number;
};

//function to find the name we are searching for 
void SEARCH(struct _data *BlackBox, char *name, int size) {
	//boolean variable to check if name was not found for case 2
	int found = 0;
	//loop through data stored in BlackBox until a match is found
	for (int i = 0; i < size; i++) {
		if (strcmp(BlackBox[i].name, name) == 0) {
			//print the found name for case 3
			printf("\nThe name %s was found at the %d entry.\n", name, i+1);
			found = 1;
			break;
		}
	}
	if (found == 0) {
		printf("\nThe name was NOT found.\n");
	}
}
