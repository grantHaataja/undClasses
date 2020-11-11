/*CSCI 451 - Assignment 10
Grant Haataja

Program 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int pipe1[2];
	int sid;
	char buffer[111];
	
	//open input file
	FILE *inFile = fopen("input.data", "r");
	
	//configure the semaphore for locking and unlocking
	struct sembuf sem_lock, sem_unlock;
	sem_lock.sem_num = 0;
	sem_lock.sem_op = -1;
	sem_lock.sem_flg = 0;
	sem_unlock.sem_num = 0;
	sem_unlock.sem_op = 1;
	sem_unlock.sem_flg = 0;
	
	//convert pipe and semaphore IDs to integers
	sid = atoi(argv[3]);
	pipe1[0] = atoi(argv[1]);
	pipe1[1] = atoi(argv[2]);
	
	//allow pipe to write without blocking
	fcntl(pipe1[1], F_SETFL, O_NONBLOCK);
	close(pipe1[0]);
	
	//read input file into buffer
	fscanf(inFile, "%s", buffer);
	
	//loop until data is read and conditions are met
	while (1) {
		//check if pipe is full, then unlock semaphore and loop again
		if (write(pipe1[1], &buffer, 111) < 0) {
			semop(sid, &sem_unlock, 1);
			continue;
		}
		semop(sid, &sem_unlock, 1);
		//check if end of file has been reached, then exit loop
		if (fscanf(inFile, "%s", buffer) == EOF) {
			break;
		}
	}
	
	//close pipe and input file
	close(pipe1[1]);
	fclose(inFile);
	
	return 0;
}
