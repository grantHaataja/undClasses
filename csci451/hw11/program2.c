/*CSCI 451 - Assignment 11
Grant Haataja

Program 2
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

//function to determine whether word is of type 1 or 2
int wordCheck(char wrd) {
	if (wrd == 'a' || wrd == 'e' || wrd == 'i' || wrd == 'o' || wrd == 'u' ||
		wrd == 'A' || wrd == 'E' || wrd == 'I' || wrd == 'O' || wrd == 'U') {
		return 1;	
	}
	return 2;	
}

//function to determine if given character is a letter
int letter(char c) {
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
		return 1;
	}
	return 0;
}

int main(int argc, char **argv) {
	int readPipe1, writePipe2;
	int sid1, sid2, shrdmem, result;
	int strLen, countType1 = 0, countType2 = 0;
	char buffer[111];
	memset(buffer, '\0', 111);

	//convert pipe and semaphore IDs to integers
	readPipe1 = atoi(argv[1]);
	writePipe2 = atoi(argv[2]);
	sid1 = atoi(argv[3]);
	sid2 = atoi(argv[4]);
	shrdmem = atoi(argv[5]);
	
	while (result = semctl(sid1, 0, GETVAL, NULL) != 2) {
		while (result = semctl(sid1, 0, GETVAL, NULL) < 1);
		while (result = semctl(sid2, 0, GETVAL, NULL) != 0);
		read(readPipe1, &buffer, 111);
		strLen = strlen(buffer);
		//if the last character is a newline, append a \0 just before
		if (buffer[strLen] == '\n') {
			buffer[strLen-1] = '\0';
		}
		//check if word is of type 1 or 2
		if (wordCheck(buffer[0]) == 1) {
			countType1++;
			//check if last character of word is a letter or punctuation
			if (letter(buffer[strLen-1])) {
				strcat(buffer, "ray");
			} else {
				//remove comma before adding "ray" to the word with a new comma
				if (buffer[strLen-1] == ',') {
					buffer[strLen-1] = '\0';
					strcat(buffer, "ray," );
				} else {
					//remove period before adding "ray" with a new period
					buffer[strLen-1] = '\0';
					strcat(buffer, "ray.");
				}
			}
		} else {
			countType2++;
			char newBuffer[111] = {'\0'};
			//check if last character of word is a letter or punctuation
			if (letter(buffer[strLen-1])) {
				//copy all but the first letter into a new buffer
				strcpy(newBuffer, buffer+1);
				//add the first letter to the end of the new buffer
				newBuffer[strLen-1] = buffer[0];
				//add "ay" to the end of the new buffer
				strcat(newBuffer, "ay");
				//copy the new buffer back into the original buffer
				strcpy(buffer, newBuffer);				
			} else {
				//copy all but the first letter into a new buffer
				strcpy(newBuffer, buffer+1);
				//replace the puct mark in the new buffer with the first letter
				newBuffer[strLen-2] = buffer[0];
				//if it's a comma, add "ay," to the end of the new buffer
				if (buffer[strLen-1] == ',') {
					strcat(newBuffer, "ay,");
				} else {
					//if it's a period, add "ay." to the end of the new buffer
					strcat(newBuffer, "ay.");
				}
				//copy the new buffer back into the original buffer
				strcpy(buffer, newBuffer);
			}
		}
		strcat(buffer, " ");
		write(writePipe2, &buffer, strlen(buffer));
		memset(buffer, '\0', 111);
		if (result = semctl(sid1, 0, GETVAL, NULL) != 2) {
			semctl(sid1, 0, SETVAL, 0);
		}
		semctl(sid2, 0, SETVAL, 1);
	}
	semctl(sid2, 0, SETVAL, 2);
	while (result = semctl(sid2, 0, GETVAL, NULL) < 3);
	
	//write the type counts to the shared memory
	int *write, *temp;
	write = (int *) shmat(shrdmem, 0, 0);
	temp = write;
	*temp ++= countType1;
	*temp = countType2;
	shmdt(write);
	shmdt(temp);
	
	//close pipe 1 and semaphore
	semctl(sid1, 0, IPC_RMID);
	semctl(sid2, 0, SETVAL, 4);
	close(readPipe1);
	
	return 0;
}
