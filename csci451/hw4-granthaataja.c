/*CSCI 451 - Assignment 4
Grant Haataja

Compile with: gcc hw4-granthaataja.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//define global variables for thread synchronization and counting
int value = 0;
pthread_t tid[2];
pthread_cond_t cond;
pthread_mutex_t locker;
int canRead = 1;
int canWrite = 0;

//thread to open given file and read its contents
void *readFile(void *arg) {
	//lock the thread using the mutex
	pthread_mutex_lock(&locker);
	//open the given input file for reading
	FILE *inFile = fopen("hw4.in", "r");
	while((fscanf(inFile, "%d\n", &value)) != EOF) {
		//set boolean to true so the other thread can write the data to file
		canWrite = 1;
		//unlock the thread using the mutex
		pthread_mutex_unlock(&locker);
		//wait for the other thread to write the data before continuing to read
		pthread_cond_wait(&cond, &locker);
	}
	//unlock the thread
	pthread_mutex_unlock(&locker);
	//set boolean to false so this thread cannot read data
	canRead = 0;
	//close input file
	fclose(inFile);
}

//thread to open a file for writing and write results to
void *writeFile(void *arg) {
	//open an output file to write to
	FILE *outFile = fopen("hw4.out", "w");
	do {
		//lock thread
		pthread_mutex_lock(&locker);
		//check if thread can write data to file
		if (canWrite == 1) {
			//check if given value is even or odd, and write accordingly
			if (value % 2 == 0) {
				fprintf(outFile, "%d\n", value);
				fprintf(outFile, "%d\n", value);
			}
			else {
				fprintf(outFile, "%d\n", value);
			}
			//set boolean to false so this thread cannot write data
			canWrite = 0;
		}
		//unlock thread
		pthread_mutex_unlock(&locker);
		//signal reading thread that it can continue reading data
		pthread_cond_signal(&cond);
	} while(canRead == 1);
	//close output file
	fclose(outFile);
}

int main() {
	//initialize mutex
	pthread_mutex_init(&locker, NULL);
	//initialize control condition
	pthread_cond_init(&cond, NULL);
	//create both threads
	pthread_create(&(tid[0]), NULL, readFile, NULL);
	pthread_create(&(tid[1]), NULL, writeFile, NULL);
	
	//call the threads to perform reading and writing
	for (int i = 0; i < 2; i++) {
		pthread_join(tid[i], NULL);
	}
	
	return 0;
}
