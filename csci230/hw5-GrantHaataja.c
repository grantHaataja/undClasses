//Grant Haataja
//Assignment 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
struct _data {                                 
	char *name;
	long number;
};

//vector function
char *vector(char *fileName, int count) {
	char * ptr;
	//allocate memory for any string
	ptr = (char*) calloc(count+1, sizeof(char));
	//copy memory into ptr to return to Main
	memcpy(ptr, fileName, count);
	return ptr;
}

//function to open the file/stream and count how many lines it contains
int SCAN(char *fileName, FILE *(*stream)) {
	int size = 0;
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
			size++;
			//free(line); //TODO WHY??
		}
		return size;
	}
}

//function to create a dynamic array of length 'size' and store data in struct
struct _data *LOAD(FILE *stream, int size) {
	char *line = NULL; //hold each individual line of file
	size_t length = 0;
	ssize_t read = 0;
	struct _data *BlackBox;
	BlackBox = calloc(size, sizeof(struct _data)); //FIXME ??
	if (BlackBox == NULL) printf("\nFAIL\n"); //FIXME delete
	if (BlackBox != NULL) printf("\nSUCCESS\n"); //FIXME delete
	//rewind stream to start at the beginning of file
	rewind(stream);
	for (int i = 0; i < size; i++) {
		read = getline(&line, &length, stream);
		line = strtok(line, " ,\n");
		BlackBox[i].name = line;
		line = strtok(NULL, " ");
		BlackBox[i].number = atol(line);
		printf("%s %ld\n", BlackBox[i].name, BlackBox[i].number); //FIXME delete
	}
	return BlackBox;
}

//function to find the name we are searching for 
void SEARCH(struct _data *BlackBox, char *name, int size) {
	//boolean variable to check if name was not found for case 2
	int found = 0;
	//loop through data stored in BlackBox until a match is found
	for (int i = 0; i < size; i++) {
		if (strcmp(BlackBox[i].name, name) == 0) {
			//print the found name for case 3
			printf("\nThe name was found at the %d entry.", i+1);
			found = 1;
		}
	}
	if (found == 0) {
		printf("\nThe name was NOT found.");
	}
}

//function to free all dynamic memory allocated in this program
void FREE(struct _data *BlackBox, int size) {


}

//Main
int main(int argc, char **argv) {
	//define name of file containing the information used in this program
	char *fileName;
	//fileName = "hw5.data";
	int size = 0; //number of lines in file
	struct _data *BlackBox;
	//declare file/stream
	FILE *fstream;
	//get user-entered file name and dynamically allocate memory for fileName
	while (1) {
		int i = 0;
		int count = 1;		
		printf("Enter a data file to search from: ");
		//allocate memory for fileName
		fileName = calloc(2, sizeof(char)); 
		while (1) {
			//get character one at a time
			fileName[i] = getchar();		  	
			//check to break
			if (fileName[i] == '\n') {
				fileName[i] = '\0';
				break;
			}	
			//call vector function to allocate memory
			fileName = vector(fileName, count);
			//count how many characters are in the fileName
			count = strlen(fileName) + 1;
			i++;
		}
		//call function to count lines in file
		if ((size = SCAN(fileName, &fstream)) != 0) {
			break;
		}	
	}
	printf("File is %d lines.", size); //FIXME delete

	//call function to store data in structure
	BlackBox = LOAD(fstream, size);
	
	//allocate memory for argv
	//argv = calloc(size, sizeof(int));
	printf("%s",argv);
	printf("\nargc is %d\n",argc);
	char *name;
	//name = calloc(size, sizeof(char));
	//name = *argv;
	//printf("name is %s\n",name);
	
	//make sure user entered a name
	if (argc <= 1) {
		printf("You must include a name to search for.\n");
		exit(0);
	}
	//loop through user-entered names and store them in an array
	for (int i = 0; i < argc-1; i++) {
		printf("\nI'm in the loop\n");
		//name[i] = calloc(
		name[i] = *argv[i+1];
		printf("entered name: %s\n",name[i]);
	}
	//call function to search for user-entered name
	//SEARCH(BlackBox, name, size);

	printf("\nProgram Complete\n"); //FIXME delete

	return 0;
}
