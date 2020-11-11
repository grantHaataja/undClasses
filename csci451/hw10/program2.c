/*CSCI 451 - Assignment 10
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
	int pipe1[2], pipe2[2];
	int sid, readStatus;
	int strLen, countType1 = 0, countType2 = 0;
	char buffer[111] = {'\0'};
	
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
	pipe2[0] = atoi(argv[4]);
	pipe2[1] = atoi(argv[5]);
	
	//allow pipe1 to read without blocking
	fcntl(pipe1[0], F_SETFL, O_NONBLOCK);
	
	//close pipes that will not be used
	close(pipe1[1]);
	close(pipe2[0]);
	
	//loop until all words have been read from pipe and converted to pig latin
	while (1) {
		semop(sid, &sem_lock, 1);
		//check if all words have been read from pipe or error received
		if ((readStatus = read(pipe1[0], &buffer, 111)) <= 0) {
			//check for end of file, and exit loop
			if (readStatus == 0) {
				semop(sid, &sem_unlock, 1);
				break;
			} else {
				//unlock semaphore and go back to start of loop
				semop(sid, &sem_unlock, 1);
				continue;
			}
		}
		semop(sid, &sem_unlock, 1);
		//convert word to pig latin
		strLen = strlen(buffer);
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
		//write result to pipe 2
		strcat(buffer, " ");
		write(pipe2[1], &buffer, 111);
	}
	
	//close pipe 1 and semaphore
	close(pipe1[0]);
	semctl(sid, 0, IPC_RMID);
	
	//create two files and write the type counts to them
	FILE *outFile1 = fopen("shared1.dat", "w");
	FILE *outFile2 = fopen("shared2.dat", "w");
	fprintf(outFile1, "%d\n", countType1);
	fprintf(outFile2, "%d\n", countType2);
	
	//close files and pipe
	fclose(outFile1);
	fclose(outFile2);
	close(pipe2[1]);
	
	return 0;
}
