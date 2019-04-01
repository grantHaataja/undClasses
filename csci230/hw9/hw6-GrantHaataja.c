//Grant Haataja
//Assignment 9: Main Routine

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6-S-GrantHaataja.h"
#include "hw6-A-GrantHaataja.h"
#include "hw6-B-GrantHaataja.h"
#include "hw6-C-GrantHaataja.h"
#include "hw6-D-GrantHaataja.h"

//Main
int main(int argc, char **argv) {
	//define name of file containing the information used in this program
	char *fileName;
	fileName = "hw5.data";
	int size = 0; //number of lines in file
	struct _data *BlackBox;
	//declare file/stream
	FILE *fstream;
	while (1) {
		//call function to count lines in file
		if ((size = SCAN(fileName, &fstream)) != 0) {
			break;
		}	
	}	
	//call function to store data in structure
	BlackBox = LOAD(fstream, size, fileName);
	//close file
	fclose(fstream);
	//make sure user entered a name
	if (argc <= 1) {
		printf("\nYou must include a name to search for.\n");
		return 0;
	}
	//call function to search for user-entered name
	SEARCH(BlackBox, *(argv+1), size);
	//call function to free memory
	FREE(BlackBox, size, fileName);

	return 0;
}
