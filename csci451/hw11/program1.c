/*CSCI 451 - Assignment 11
Grant Haataja

Program 1
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
	int sid, writePipe1;
	char tempBuffer[111];
	memset(tempBuffer, '\0', 111);
	char buffer[111];
	memset(buffer, '\0', 111);
	char in;
	int step = 0;
	
	//open input file
	int inFile = open(argv[1], O_RDONLY);

	//convert pipe and semaphore IDs to integers
	sid = atoi(argv[3]);
	writePipe1 = atoi(argv[2]);
	int result;

	//loop until data is read and conditions are met
	while (read(inFile, &in, 1) != 0) {
		while ((result = semctl(sid, 0, GETVAL, NULL)) > 0);
		if (in != ' ') {
			tempBuffer[step] = in;
			step++;
		} else {
			strcpy(buffer, tempBuffer);
			write(writePipe1, buffer, strlen(buffer));
			semctl(sid, 0, SETVAL, 1);
			step = 0;
			memset(tempBuffer, '\0', 111);
		}
	}
	while (result = semctl(sid, 0, GETVAL, NULL) > 0);
	strcpy(buffer, tempBuffer);
	buffer[strlen(buffer)-1] = '\0';
	write(writePipe1, buffer, strlen(buffer));
	semctl(sid, 0, SETVAL, 1);
	step = 0;
	memset(tempBuffer, '\0', 111);
	semctl(sid, 0, SETVAL, 2);
	
	//close pipe and input file
	close(writePipe1);
	close(inFile);
	
	return 0;
}
