//Grant Haataja
//CSCI230: Assignment 3

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Functions

//open files and check length of files
int fileOpen(char fileName[]) {
	int lines = 0;
	char dummy[60];
	while (1) {
		printf("Enter a text file name: ");
		scanf(" %s", fileName);
		FILE *stream = fopen(fileName,"r");
		if (stream == NULL) {
			printf("File not found...\n");
		}
		else {
			while(!feof(stream)) {
				fscanf(stream,"%s", dummy);
				lines++;
			}
			return lines - 1;
		}
	}
}

//parse through files, allocate memory, and store contents in array of string
void getData(int lines0, int lines1, int lines2, char fileName0[], 
		char fileName1[], char fileName2[], char **words) {
	int i = 0; int j = 0; int k = 0;
	//open file0
	FILE *stream0 = fopen(fileName0,"r");
	if (stream0 == NULL) {
		printf("File not found...\n");
	}
	else {
		//parse through file0 and cat contents to array "words"
		for (i = 0; i < lines0; i++) {
			words[i] = (char *) malloc(sizeof(char) * 60);
			fscanf(stream0, " %s", words[i]);
		}
	}
	fclose(stream0);	
	//open file1
	FILE *stream1 = fopen(fileName1,"r");
	if (stream1 == NULL) {
		printf("File not found...\n");
	}
	else {
		//parse through file1 and cat contents to array "words"
		for (j = lines0; j < lines0 + lines1; j++) {
			words[j] = (char *) malloc(sizeof(char) * 60);
			fscanf(stream1, " %s", words[j]);
		}
	}
	fclose(stream1);	
	//open file2
	FILE *stream2 = fopen(fileName2,"r");
	if (stream2 == NULL) {
		printf("File not found...\n");
	}
	else {
		//parse through file2 and cat contents to array "words"
		for (int k = lines0 + lines1; k < lines0 + lines1 + lines2; k++) {
			words[k] = (char *) malloc(sizeof(char) * 60);
			fscanf(stream2, " %s", words[k]);
		}
	}
	fclose(stream2);
}

//sort array alphabetically
void sort(char **words, int totalLines) {
	for (int i = 0; i < totalLines - 1; i++) {
		for (int j = 0; j < totalLines - i - 1; j++) {
			if (strcmp(words[j], words[j+1]) > 0) {
				char *temp;
				temp = (char *) malloc(sizeof(char) * 60);
				strcpy(temp, words[j]);
				strcpy(words[j], words[j+1]);
				strcpy(words[j+1], temp);
			}
		}
	}
}

//print sorted array of words to an output file
void write(char **words, int totalLines) {
	FILE *stream = fopen("words.txt", "w");
	for (int i = 0; i < totalLines; i++) {
		fprintf(stream, "%s\n", words[i]);
	}
	fclose(stream);
}

//Main Routine
int main(void) {
	char **words;
	int lines0 = 0;
	int lines1 = 0;
	int lines2 = 0;
	int totalLines = 0;
	char file0[60];
	char file1[60];
	char file2[60];
	//ask user to input names of files
	printf("Enter 3 file names to be merged and sorted: \n");
	//first count total number of lines in all 3 files
	lines0 = fileOpen(file0);
	//strcpy(fileName, "american1.txt");
	lines1 = fileOpen(file1);
	//strcpy(fileName, "american2.txt");
	lines2 = fileOpen(file2);
	totalLines = lines0 + lines1 + lines2;
	//allocate memory for first dimension of array (number of words)
	words = (char **) malloc(sizeof(char*) * (totalLines + 1));
	//call function to allocate memory for second dimension (size of each word)
	getData(lines0, lines1, lines2, file0, file1, file2, words);
	//call function to sort array alphabetically
	sort(words, totalLines);
	//call function to print sorted word list to output file
	write(words, totalLines);
	//free allocated memory for array of words
	free(words);
}

