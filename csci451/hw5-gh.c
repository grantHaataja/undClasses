/*CSCI 451 - Assignment 5
Grant Haataja

Compile with: gcc hw5-granthaataja.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//define global variables
char value = '#';
pthread_t tid[3];
pthread_cond_t canRead;
pthread_cond_t canWrite;
pthread_mutex_t locker;
int fileNotEmpty = 1;
int thread1CanRead = 1;
int thread2CanRead = 0;

//thread #1 to open file 1 and read its contents
void *thread1(void *arg) {
	//lock the thread using the mutex
	pthread_mutex_lock(&locker);
	//open input file 1 to read
	FILE *file1 = fopen("hw5-1.in", "r");
	//read one character at a time from input file and store it in global value
	while (thread1CanRead && fscanf(file1, "%c\n", &value) != EOF) {
		printf("Current value is: %c\n", value); //FIXME
		thread1CanRead = 0;
		//lock thread after reading one character from input file
		//printf("Locking thread 1 with mutex...\n\n"); //FIXME
		//pthread_mutex_lock(&locker);
		//signal main that it can write the value to output file
		printf("Sending signal 'canWrite' to main...\n\n"); //FIXME
		pthread_cond_signal(&canWrite);
		//wait until canRead condition is met
		printf("Thread 1 will wait until 'canRead' condition is signalled...\n\n"); //FIXME
		pthread_cond_wait(&canRead, &locker);
		//unlock thread
		printf("Unlocking thread 1 with mutex...\n\n"); //FIXME
		pthread_mutex_unlock(&locker);
	}
	//close input file
	fclose(file1);
	//set fileNotEmpty boolean to false
	fileNotEmpty = 0;
	//exit thread
	printf("Exitting thread 1...\n\n"); //FIXME
	pthread_cond_signal(&canWrite);
	pthread_exit(NULL);
}

//thread #2 to open file 2 and read its contents
void *thread2(void *arg) {
	//lock the thread using the mutex
	pthread_mutex_lock(&locker);
	//open input file 2 to read
	FILE *file2 = fopen("hw5-2.in", "r");
	//read one character at a time from input file and store it in global value
	while (thread2CanRead && fscanf(file2, "%c\n", &value) != EOF) {
		printf("Current value is: %c\n", value); //FIXME
		thread2CanRead = 0;
		//lock thread after reading one character from input file
		//printf("Locking thread 1 with mutex...\n\n"); //FIXME
		//pthread_mutex_lock(&locker);
		//signal main that it can write the value to output file
		printf("Sending signal 'canWrite' to main...\n\n"); //FIXME
		pthread_cond_signal(&canWrite);
		//wait until canRead condition is met
		printf("Thread 2 will wait until 'canRead' condition is signalled...\n\n"); //FIXME
		pthread_cond_wait(&canRead, &locker);
		//unlock thread
		printf("Unlocking thread 2 with mutex...\n\n"); //FIXME
		pthread_mutex_unlock(&locker);
	}
	//close input file
	fclose(file2);
	//set fileNotEmpty boolean to false
	fileNotEmpty = 0;
	//exit thread
	printf("Exitting thread 2...\n\n"); //FIXME
	pthread_cond_signal(&canWrite);
	pthread_exit(NULL);
}

//thread #3 to open file 3 and read its contents
void *thread3(void *arg) {
	
}

int main() {
	//open file hw5.out for writing
	FILE *writeFile = fopen("hw5.out", "w");
	//initialize mutex and conditions
	pthread_mutex_init(&locker, NULL);
	pthread_cond_init(&canRead, NULL);
	pthread_cond_init(&canWrite, NULL);
	int turnCounter = 0;
	
	printf("Creating 3 threads to do some work...\n\n"); //FIXME
	//create 3 threads and wait for them to tell main it can write
	//for (int i = 0; i < 3; i++) {
	//	printf("Locking main thread with mutex...\n\n"); //FIXME
	//	pthread_mutex_lock(&locker);
	//	printf("Creating thread %d...\n\n", i); //FIXME
	//	pthread_create(&(tid[i]), NULL, thread1, NULL);
	//	//wait until thread signals main can write
	//	printf("Main will wait until condition 'canWrite' is signaled...\n\n"); //FIXME
	//	pthread_cond_wait(&canWrite, &locker);
	//	printf("Unlocking main thread with mutex...\n\n"); //FIXME
	//	pthread_mutex_unlock(&locker);
	//}
	pthread_create(&(tid[1]), NULL, thread1, NULL);
	pthread_create(&(tid[2]), NULL, thread2, NULL);
	pthread_create(&(tid[3]), NULL, thread3, NULL);
	
	pthread_cond_broadcast(&canRead);
	pthread_cond_wait(&canWrite, &locker);
	printf("Starting process of copying characters...\n\n"); //FIXME
	//copy characters from global variable and write them to output file
	while (fileNotEmpty) {
		//printf("Locking main thread with mutex...\n\n"); //FIXME
		//pthread_mutex_lock(&locker);
		//pthread_cond_wait(&canWrite, &locker);
		if (turnCounter % 3 == 0) {
			printf("Printing value from thread 1...\n\n"); //FIXME
			thread1CanRead = 0;
			thread2CanRead = 1;
		}
		if (turnCounter % 3 == 1) {
			thread1CanRead = 1;
			thread2CanRead = 0;
		}
		printf("Writing %c to file...\n\n", value); //FIXME
		fprintf(writeFile, "%c\n", value);
		pthread_cond_broadcast(&canRead);
		pthread_mutex_unlock(&locker);
		printf("Main will wait until condition 'canWrite' is signalled...\n\n"); //FIXME
		pthread_cond_wait(&canWrite, &locker);
	}
	printf("Finished process of copying characters...\n\n"); //FIXME

	//join threads
	//for (int i = 0; i < 3; i++) {
	//	printf("Joining thread %d...\n\n", i); //FIXME
	//	if (pthread_join(tid[i], NULL) != 0) {
	//		printf("Thread %d failed to join\n", i);
	//	}
	//}
	
	//close the write out file
	fclose(writeFile);	
	return 0;
}
