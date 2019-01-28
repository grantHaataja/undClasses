//Grant Haataja

#include<stdlib.h>
#include<stdio.h>

//Functions

//open files and check length of files
int fileOpen(void) {
	int lines = 0;
	char fileName[20];
	char dummy[20];
	while(1) {
		printf("Enter a text file name: ");
		scanf(" %s", fileName);
		FILE *stream = fopen(fileName,"r");
		if(stream == NULL) {
			printf("File not found...\n");
		}
		else {
			while(!feof(stream)) {
				fscanf(stream,"%s", dummy);
				lines++;
			}
			return lines;
		}
	}
}

//Main Routine
int main(void) {
	int lines = 0;
	lines = fileOpen();
	printf("%d\n", lines); //FIXME delete
}
