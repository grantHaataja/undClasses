/*CSCI 451 - Assignment 9
Grant Haataja

Compile with: gcc hw9-granthaataja.c -pthread
Run with: ./a.out nomutex OR ./a.out mutex

Analysis:
When running in "nomutex" mode, the threads will take one word at a time from
the input file and write them to the output file. This results in non-consistent
formatting of the output file, i.e. the words appear in different order than 
they appear in the input file.

When running in "mutex" mode, the threads do the same thing except they set a 
mutex before reading and writing the word, so no other threads can read or write
until they finish their word. This results in consistent formatting of the 
output file. The words appear in the exact same order which they appeared in 
the input file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

//define global variables
struct threadData {
	int id;
	int mutexMode;
	FILE *inFile;
	FILE *outFile;
};
pthread_mutex_t locker;
pthread_cond_t canWrite;
pthread_barrier_t wall;

//thread function body for all threads
void *threadFunc(void *arg)
{
	struct threadData *thread;
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	pthread_mutex_lock(&locker);
	//give each thread a unique ID
	thread = (struct threadData *) arg;
	int threadID = thread->id;
	pthread_cond_signal(&canWrite);
	pthread_mutex_unlock(&locker);
	//wait for all threads to be initialized before proceeding with task
	pthread_barrier_wait(&wall);
	
	//read one word at a time from input file and write it to output file
	while (1) {
		//set a mutex if program is running in mutex mode
		if (thread->mutexMode) {
			pthread_mutex_lock(&locker);
		}
		if ((read = getline(&line, &length, thread->inFile)) != -1) {
			//check for newlines to strip off
			size_t last_idx = strlen(line) - 1;
			if (line[last_idx] == '\n') {
				line[last_idx] = '\0';
			}
			//write the word to output file in specified format
			fprintf(thread->outFile, "%s\t%d\n", line, threadID);
			//unlock mutex if running in mutex mode
			if (thread->mutexMode) {
				pthread_mutex_unlock(&locker);
			}
			//sleep for a second
			sleep(1);
		}
		else {
			//unlock mutex if running in mutex mode
			if (thread->mutexMode) {
				pthread_mutex_unlock(&locker);
			}
			break;
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	pthread_t tid[10];
	struct threadData thread;
	//initialize mutex
	pthread_mutex_init(&locker, NULL);
	pthread_cond_init(&canWrite, NULL);
	pthread_barrier_init(&wall, NULL, 10);
	//open files
	FILE *in = fopen("hw9.data", "r");
	FILE *out;
	if (argc != 2) {
		printf("Improper command-line arguments specified.\n");
		printf("Please type: <./a.out mutex> to run in mutex mode.\n");
		printf("Please type: <./a.out nomutex> to run in non-mutex mode.\n");
		exit(0);
	}
	if (strcmp(argv[1], "nomutex") == 0) {
		out = fopen("hw9.nomutex", "w");
		thread.mutexMode = 0;
	}
	else if (strcmp(argv[1], "mutex") == 0) {
		out = fopen("hw9.mutex", "w");
		thread.mutexMode = 1;
	}
	else {
		printf("Improper command-line arguments specified.\n");
		printf("Please type: <./a.out mutex> to run in mutex mode.\n");
		printf("Please type: <./a.out nomutex> to run in non-mutex mode.\n");
		exit(0);
	}
	thread.inFile = in;
	thread.outFile = out;
	
	//spawn 10 threads
	for (int i = 0; i < 10; i++) {
		pthread_mutex_lock(&locker);
		thread.id = i;
		pthread_create(&(tid[i]), NULL, threadFunc, (void *) &thread);
		pthread_cond_wait(&canWrite, &locker);
		pthread_mutex_unlock(&locker);
	}
	
	printf("Beginning Reading and Writing Process.\n");
	//let the threads run wild and free
	sleep(3);
	
	//join threads
	for (int i = 0; i < 10; i++) {
		pthread_join(tid[i], NULL);
	}
	
	//clean up
	fclose(in);
	fclose(out);
	pthread_mutex_destroy(&locker);
	pthread_cond_destroy(&canWrite);
	pthread_barrier_destroy(&wall);

	return 0;
}
