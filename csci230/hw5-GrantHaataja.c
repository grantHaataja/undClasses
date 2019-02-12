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
char * vector(char *fileName, int count) {
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
	char *temp;
	printf("Just to check, fileName is %s\n",fileName); //FIXME
	//check if file is valid
	if ((*stream = fopen(fileName, "r")) == NULL) {
		printf("\nFile not found...\n");
		free(fileName);
		return 0;
	}
	else {
		printf("YAY!\n"); //FIXME
		
		return size;
	}
	//*stream = fopen(fileName, "r");
	printf("\n???\n"); //FIXME
		
		/*else {
			while (1) {
				if (feof(*stream)) {
					break;
				}
				fscanf(*stream, "%s", temp);
				size++;
			}
		return size;
		printf("SCAN function successful"); //FIXME delete
		}*/

}

//function to create a dynamic array of length 'size' and store data in struct
struct _data *LOAD(FILE *stream, int size) {


}

//function to find the name we are searching for 
void SEARCH(struct _data *BlackBox, char *name, int size) {


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
	FILE *fstream; //declare file/stream
	//get user-entered file name and dynamically allocate memory for fileName
	//loop until user enters a valid file name
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
				break;
			}	
			//call vector function to allocate memory
			fileName = vector(fileName, count);
			//count how many characters are in the fileName
			count = strlen(fileName) + 1;
			i++;
		}
	printf("\nfile name is %s \n", fileName); //FIXME
	//call function to count lines in file
	size = SCAN(fileName, &fstream);
	}


	printf("\nProgram Complete\n"); //FIXME delete

	return 0;
}
