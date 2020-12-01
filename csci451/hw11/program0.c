/*CSCI 451 - Assignment 11
Grant Haataja

Program 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
	//get command line args and validate them
	if (argc != 3) {
		printf("Usage: ./program0 <input_file> <output_file>\n");
		exit(0);
	} 
	char *inFile = argv[1];
	char *outFile = argv[2];
	
	//create semaphores
	key_t semKey1 = ftok("input.data", 1);
	key_t semKey2 = ftok("output.data", 1);
	int sid1, sid2, status;
	sid1 = semget(semKey1, 1, 0660 | IPC_CREAT);
	semctl(sid1, 0, SETVAL, 0);
	sid2 = semget(semKey2, 1, 0660 | IPC_CREAT);
	semctl(sid2, 0, SETVAL, 0);
	
	//create shared memory segment
	key_t semKey3 = ftok("program0.c", 3);
	int shrdmem = shmget(semKey3, 27, 0660 | IPC_CREAT);
	
	//create pipes
	int pipe1[2], pipe2[2];
	pipe(pipe1);
	pipe(pipe2);
	
	//create IDs for pipe and semaphore combinations
	pid_t pid1, pid2, pid3;
	char readPipe1[3], writePipe1[3], readPipe2[3], writePipe2[3];
	char sem1C[10], sem2C[10], sharedMem[10];
	sprintf(readPipe1, "%d", pipe1[0]);
	sprintf(writePipe1, "%d", pipe1[1]);
	sprintf(readPipe2, "%d", pipe2[0]);
	sprintf(writePipe2, "%d", pipe2[1]);
	sprintf(sem1C, "%d", sid1);
	sprintf(sem2C, "%d", sid2);
	sprintf(sharedMem, "%d", shrdmem);
	
	//fork program 1
	if ((pid1 = fork()) == 0) {
		char *args[] = 
			{"./program1", inFile, writePipe1, sem1C, NULL};
		execv(args[0], args);
	}
	//fork program 2
	if ((pid2 = fork()) == 0) {
		char *args[] = 
			{"./program2",readPipe1, writePipe2, sem1C, sem2C, sharedMem, NULL};
		execv(args[0], args);
	}
	//fork program 3
	if ((pid3 = fork()) == 0) {
		char *args[] = 
			{"./program3", outFile, readPipe2, sem2C, sharedMem, NULL};
		execv(args[0], args);
	}

	//wait for programs 1, 2, and 3 to finish
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	waitpid(pid3, &status, 0);
	
	semctl(sid1, 0, IPC_RMID, 0);
	semctl(sid2, 0, IPC_RMID, 0);
	
	return 0;
}
