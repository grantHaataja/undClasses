/*CSCI 451 - Assignment 11
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
#include <sys/shm.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int readPipe2, sid, shrdmem, result;
	char buffer[111];
	
	//open output file
	FILE *outFile = fopen(argv[1], "w");
	
	//convert pipe and semaphore IDs to integers
	readPipe2 = atoi(argv[2]);
	sid = atoi(argv[3]);
	shrdmem = atoi(argv[4]);

	//loop until all data is read from pipe and written to output file
	while (result = semctl(sid, 0, GETVAL, NULL) < 2) {
		while (result = semctl(sid, 0, GETVAL, NULL) < 1);
		if (read(readPipe2, &buffer, 111) == -1) {
			break;
		}
		printf("Word: %s\n", buffer);
		fprintf(outFile, "%s", buffer);
		memset(buffer, '\0', 111);
		if (result = semctl(sid, 0, GETVAL, NULL) < 2) {
			semctl(sid, 0, SETVAL, 0);
		}
	}
	semctl(sid, 0, SETVAL, 3);
	while (result = semctl(sid, 0, GETVAL, NULL) < 4);
	
	//get type data from shared memory and print to screen	
	int *read, *temp;
	read = (int *) shmat(shrdmem, 0, 0);
	temp = read;
	printf("Type 1: %d\n", *temp);
	*temp++;
	printf("Type 2: %d\n", *temp);
	shmdt(read);
	shmdt(temp);
	shmctl(shrdmem, IPC_RMID, NULL);
	semctl(sid, 0, IPC_RMID, 0);
	
	//close pipe and files
	close(readPipe2);
	fclose(outFile);

	return 0;
}
