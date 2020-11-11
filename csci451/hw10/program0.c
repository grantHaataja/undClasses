/*CSCI 451 - Assignment 10
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
#include <sys/wait.h>

int main(int argc, char ** argv) {
	//create semaphore
	key_t semKey = ftok("input.data", 1);
	int sid, status;
	sid = semget(semKey, 1, 0660 | IPC_CREAT);
	semctl(sid, 0, SETVAL, 0);

	//create pipes
	int pipe1[2], pipe2[2];
	pipe(pipe1);
	pipe(pipe2);
	
	//create IDs for pipe and semaphore combinations
	pid_t pid1, pid2, pid3;
	char readPipe1[3], writePipe1[3], readPipe2[3], writePipe2[3], semC[10];
	sprintf(readPipe1, "%d", pipe1[0]);
	sprintf(writePipe1, "%d", pipe1[1]);
	sprintf(readPipe2, "%d", pipe2[0]);
	sprintf(writePipe2, "%d", pipe2[1]);
	sprintf(semC, "%d", sid);
	
	//fork program 1
	if ((pid1 = fork()) == 0) {
		char *args[] = {"./program1", readPipe1, writePipe1, semC, NULL};
		execv(args[0], args);
	}
	//fork program 2
	if ((pid2 = fork()) == 0) {
		char *args[] = {"./program2", readPipe1, writePipe1, semC, readPipe2,
			writePipe2, NULL};
		execv(args[0], args);
	}
	
	//close pipe 1
	close(pipe1[0]);
	close(pipe1[1]);
	
	//fork program 3
	if ((pid3 = fork()) == 0) {
		char *args[] = {"./program3", readPipe2, writePipe2, NULL};
		execv(args[0], args);
	}
	
	//close pipe 2
	close(pipe2[0]);
	close(pipe2[1]);
	
	//wait for programs 1, 2, and 3 to finish
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	waitpid(pid3, &status, 0);
	
	return 0;
}
