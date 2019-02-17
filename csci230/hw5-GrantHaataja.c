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

//function to create a dynamic array of length 'size' and store data in struct
struct _data *LOAD(FILE *stream, int size, char *fileName) {
	//hold each individual line of file
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line
	ssize_t read = 0;
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
		read = getline(&line, &length, stream);
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
		fileName = (char *) calloc(2, sizeof(char)); 
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
