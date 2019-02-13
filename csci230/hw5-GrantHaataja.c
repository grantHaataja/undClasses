//Grant Haataja
//Assignment 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
struct data {                                 
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
		}
		return size;
	}
}

//function to create a dynamic array of length 'size' and store data in struct
struct data *LOAD(FILE *stream, int size) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	struct data *BlackBox;
	BlackBox = calloc(size, sizeof(char)); //FIXME
	//rewind stream to start at the beginning of file
	rewind(stream);
	for (int i = 0; i < size; i++) {
		//read = getline(&line, &length, stream);
		fscanf(stream, "%s %f", BlackBox[i].name, &BlackBox[i].number);
		//BlackBox[i] = line;
		printf("\n%s %f\n", BlackBox[i].name, BlackBox[i].number);
		//TODO fix code to store data properly in structure
	}

	return BlackBox;
}

//function to find the name we are searching for 
void SEARCH(struct data *BlackBox, char *name, int size) {


}

//function to free all dynamic memory allocated in this program
void FREE(struct data *BlackBox, int size) {


}

//Main
int main(int argc, char **argv) {
	//define name of file containing the information used in this program
	char *fileName;
	//fileName = "hw5.data";
	int size = 0; //number of lines in file
	struct data *BlackBox;
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
	printf("File is %d lines.", size);

	//call function to store data in structure
	BlackBox = LOAD(fstream, size);

	printf("\nProgram Complete\n"); //FIXME delete

	return 0;
}
