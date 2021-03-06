/*CSCI 451 - Assignment 5
Grant Haataja

Compile with: gcc hw5-granthaataja.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//define global variables
struct threadData {
	char val;
	int turn;
	int valCount;
	int id;
	int isFinished;
};
pthread_t tid[3];
pthread_cond_t canRead;
pthread_cond_t canWrite;
pthread_mutex_t locker;
pthread_barrier_t wall;

//thread function body for all threads
void *threadFunc(void *arg) {
	char temp = '#';
	struct threadData *thread;
	pthread_mutex_lock(&locker);
	//assign thread data to current thread
	thread = (struct threadData *) arg;
	//assign current thread ID to differentiate between the three threads
	int threadID = thread->id;
	//send control signal back to main
	pthread_cond_signal(&canWrite);
	pthread_mutex_unlock(&locker);
	//wait for all threads to be created and have their data populated
	pthread_barrier_wait(&wall);

	//define filename to handle each of the three input files
	char filename[9];
	sprintf(filename, "hw5-%d.in", (threadID+1));
	FILE *inFile = fopen(filename, "r");
	
	//read one character at a time from input file and store it in global value
	while (fscanf(inFile, "%c\n", &temp) != EOF) {
		pthread_mutex_lock(&locker);
		//wait until there are no more vals to write or current thread's turn
		while (thread->valCount > 0 || thread->turn != threadID) {
			pthread_cond_wait(&canRead, &locker);
		}
		//assign the read value to the thread's stored char value
		thread->val = temp;
		//increment the number of read values
		thread->valCount++;
		//send control signal back to main
		pthread_cond_signal(&canWrite);
		pthread_mutex_unlock(&locker);
	}
	//once the first thread is done finish and exit all threads
	if (threadID == 0) {
		pthread_mutex_lock(&locker);
		//wait until there are no more vals to write or current thread's turn
		while (thread->valCount > 0 || thread->turn != threadID) {
			pthread_cond_wait(&canRead, &locker);
		}
		//set variable to 1 to tell main that all reading is complete
		thread->isFinished = 1;
		//increment number of read values so the main loop can finish
		thread->valCount++;
		//sent control signal back to main
		pthread_cond_signal(&canWrite);
		pthread_mutex_unlock(&locker);
	}
	//close input file and exit thread
	fclose(inFile);
	pthread_exit(NULL);
}

int main() {
	char value = '$';
	struct threadData thread;
	thread.turn = 0;
	thread.valCount = 0;
	thread.isFinished = 0;
	//open file hw5.out for writing
	FILE *outFile = fopen("hw5.out", "w");
	//initialize mutex and conditions
	pthread_mutex_init(&locker, NULL);
	pthread_cond_init(&canRead, NULL);
	pthread_cond_init(&canWrite, NULL);
	pthread_barrier_init(&wall, NULL, 3);
	
	//create 3 threads
	for (int i = 0; i < 3; i++) {
		pthread_mutex_lock(&locker);
		thread.id = i;
		pthread_create(&(tid[i]), NULL, threadFunc, (void *) &thread);
		//wait until thread sends control back to main
		pthread_cond_wait(&canWrite, &locker);
		pthread_mutex_unlock(&locker);
	}
	
	//write characters to output file
	while (1) {
		pthread_mutex_lock(&locker);
		//wait until there are values to write
		while (thread.valCount < 1) {
			pthread_cond_wait(&canWrite, &locker);
		}
		//check if there are no more values to write
		if (thread.isFinished == 1 && thread.turn == 0) {
			pthread_mutex_unlock(&locker);
			break;
		}
		//assign the char the current thread just read to the writing variable		
		value = thread.val;
		//decrement valCount to restart this process		
		thread.valCount--;
		//increment variable to keep track of which reading thread has control		
		thread.turn = (thread.turn + 1) % 3;
		//send broadcast signal so all threads know they can read again		
		pthread_cond_broadcast(&canRead);
		pthread_mutex_unlock(&locker);
		//write value to output file		
		fprintf(outFile, "%c\n", value);
	}

	//join the threads so everything is synchronized
	for (int i = 0; i < 3; i++) {
		pthread_join(tid[i], NULL);
	}
	
	//clean up
	fclose(outFile);
	pthread_mutex_destroy(&locker);
	pthread_cond_destroy(&canRead);
	pthread_cond_destroy(&canWrite);
	pthread_barrier_destroy(&wall);
		
	return 0;
}
