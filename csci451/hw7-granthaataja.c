/*CSCI 451 - Assignment 7
Grant Haataja

Compile with: gcc hw7-granthaataja.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

//define global variables
float accountBalance = 0.0f;
pthread_mutex_t locker;

//thread function body for Vlad
void *vlad(void *arg) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	int updateBalance = 0;
	float temp = 0.0f;
	FILE *inFile = fopen("Vlad.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break 
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					//printf("ADDING %f TO ACCOUNT BALANCE.\n", temp); //FIXME
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Vlad is $%.2f\n", 
						accountBalance);
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
			}
		}
		else {
			printf("This shouldn't happen\n");
			fclose(inFile);
			pthread_exit(NULL);
		}	
	}
	fclose(inFile);
	pthread_exit(NULL);		
}

//thread function body for Frank
void *frank(void *arg) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	int updateBalance = 0;
	float temp = 0.0f;
	FILE *inFile = fopen("Frank.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					//printf("ADDING %f TO ACCOUNT BALANCE.\n", temp); //FIXME
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Frank is $%.2f\n", 
						accountBalance);
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
			}
		}
		else {
			printf("This shouldn't happen\n");
			fclose(inFile);
			pthread_exit(NULL);
		}	
	}
	fclose(inFile);
	pthread_exit(NULL);		
}

//thread function body for Bigfoot
void *bigfoot(void *arg) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	int updateBalance = 0;
	float temp = 0.0f;
	FILE *inFile = fopen("Bigfoot.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					//printf("ADDING %f TO ACCOUNT BALANCE.\n", temp); //FIXME
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Bigfoot is $%.2f\n", 
						accountBalance);
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
			}
		}
		else {
			printf("This shouldn't happen\n");
			fclose(inFile);
			pthread_exit(NULL);
		}	
	}
	fclose(inFile);
	pthread_exit(NULL);		
}

//thread function body for Casper
void *casper(void *arg) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	int updateBalance = 0;
	float temp = 0.0f;
	FILE *inFile = fopen("Casper.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					//printf("ADDING %f TO ACCOUNT BALANCE.\n", temp); //FIXME
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Casper is $%.2f\n", 
						accountBalance);
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
			}
		}
		else {
			printf("This shouldn't happen\n");
			fclose(inFile);
			pthread_exit(NULL);
		}	
	}
	fclose(inFile);
	pthread_exit(NULL);		
}

//thread function body for Gomez
void *gomez(void *arg) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	int updateBalance = 0;
	float temp = 0.0f;
	FILE *inFile = fopen("Gomez.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					//printf("ADDING %f TO ACCOUNT BALANCE.\n", temp); //FIXME
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Gomez is $%.2f\n", 
						accountBalance);
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
			}
		}
		else {
			printf("This shouldn't happen\n");
			fclose(inFile);
			pthread_exit(NULL);
		}	
	}
	printf("Exiting thread Gomez.\n");
	fclose(inFile);
	pthread_exit(NULL);		
}

int main() {
	// initialize mutexes
	pthread_mutex_init(&locker, NULL);
	
	printf("Account balance initially is $%.2f\n", accountBalance);
	
	//spawn threads
	pthread_t tid[5];
	pthread_create(&(tid[0]), NULL, vlad, NULL);
	pthread_create(&(tid[1]), NULL, frank, NULL);
	pthread_create(&(tid[2]), NULL, bigfoot, NULL);
	pthread_create(&(tid[3]), NULL, casper, NULL);
	pthread_create(&(tid[4]), NULL, gomez, NULL);
	
	//let the threads run wild and free
	sleep(5);
	
	//detach threads
	for (int i = 0; i < 5; i++ ) {
		//printf("Detaching thread number %d\n", i); //FIXME
		pthread_detach(tid[i]);
	}
	
	printf("Account balance finally is $%.2f\n", accountBalance);
	
	//clean up
	pthread_mutex_destroy(&locker);

	return 0;
}
