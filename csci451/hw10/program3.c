/*CSCI 451 - Assignment 10
Grant Haataja

Program 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int pipe2[2], count1, count2;
	char buffer[111];
	
	//open output file
	FILE *outFile = fopen("output.data", "w");
	
	//convert pipe IDs to integers
	pipe2[0] = atoi(argv[1]);
	pipe2[1] = atoi(argv[2]);
	
	//close writing pipe
	close(pipe2[1]);
	
	//loop until all data is read from pipe and written to output file
	while (read(pipe2[0], &buffer, 111) > 0) {
		fprintf(outFile, "%s", buffer);
	}
	
	//open input files
	FILE *inFile1 = fopen("shared1.dat", "r");
	FILE *inFile2 = fopen("shared2.dat", "r");

	//display type counts
	fscanf(inFile1, "%d", &count1);
	fscanf(inFile2, "%d", &count2);
	printf("Type 1: %d\n", count1);
	printf("Type 2: %d\n", count2);
	
	//close pipe and files
	close(pipe2[0]);
	fclose(outFile);
	fclose(inFile1);
	fclose(inFile2);
	
	return 0;
}
