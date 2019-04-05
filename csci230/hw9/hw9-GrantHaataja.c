//Grant Haataja
//Assignment 9: Main Routine

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "libHW9.h"

//Main
int main(int argc, char **argv) {
	//define variables
	void *handle;
	char *error;
	//define prototypes
	int (*SCAN)(char*, FILE**);
	struct _data* (*LOAD)(FILE*, int, char*);
	void (*SEARCH)(struct _data*, char*, int);
	void (*FREE)(struct _data*, int, char*);
	
	//dlopen executable for shared library
	handle = dlopen("./libHW9.so", RTLD_NOW);
	if (!handle) {
		printf("Error in opening library\n");
		exit(0);
	}
	
	//add functions from shared library to symbol table
	*(void **) (&SCAN) = dlsym(handle, "SCAN");
	if ((error = dlerror()) != NULL) {
		printf("Error in adding function from library\n");
		exit(0);
	}
	*(void **) (&LOAD) = dlsym(handle, "LOAD");
	if ((error = dlerror()) != NULL) {
		printf("Error in adding function from library\n");
		exit(0);
	}
	*(void **) (&SEARCH) = dlsym(handle, "SEARCH");
	if ((error = dlerror()) != NULL) {
		printf("Error in adding function from library\n");
		exit(0);
	}
	*(void **) (&FREE) = dlsym(handle, "FREE");
	if ((error = dlerror()) != NULL) {
		printf("Error in adding function from library\n");
		exit(0);
	}
	
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
	//dlclose executable for shared library
	dlclose(handle);

	return 0;
}
