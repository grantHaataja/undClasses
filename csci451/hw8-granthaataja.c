/*CSCI 451 - Assignment 8
Grant Haataja

Compile with: gcc hw8-granthaataja.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

//define global variables
float accountBalance = 0.0f;
pthread_mutex_t locker;
pthread_mutex_t linker;

struct Node {
	//char use;
	int referenced;
	int modified;
	struct Node* next;
};

void setBitsToZero(struct Node *current) {
	for (int i = 0; i < 6; i++) {
		current->referenced = 0;
		current->modified = 0;
		current = current->next;
	}
}

void setRToZero(struct Node *current) {
	printf("SETTING ALL R BITS TO ZERO\n"); //FIXME
	for (int i = 0; i < 6; i++) {
		current->referenced = 0;
		current = current->next;
	}
}

void pageFault(struct Node *current) {
	struct Node *another = (struct Node *) calloc(1, sizeof(struct Node));
	printf("Current page R bit: %d\n", current->referenced);
	printf("Current page M bit: %d\n", current->modified);
	//ownership?
	another = current->next;
	int class = rand() % 4;
	switch(class) {
		case 0:
			another->referenced = 0;
			another->modified = 0;
		break;
		case 1:
			another->referenced = 0;
			another->modified = 1;
		break;
		case 2:
			another->referenced = 1;
			another->modified = 0;
		break;
		case 3:
			another->referenced = 1;
			another->modified = 1;
		break;
		default:
			printf("Error in random number generation.\n");
		break;
	}
}

//thread function body for Vlad
void *vlad(void *arg) {
	char *line = NULL;
	size_t length = 0;
	ssize_t read = 0;
	int updateBalance = 0;
	float temp = 0.0f;
	pthread_mutex_lock(&linker);
	struct Node *current = (struct Node *) calloc(1, sizeof(struct Node));
	current = (struct Node *) arg;
	pthread_mutex_unlock(&linker);
	FILE *inFile = fopen("Vlad.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break 
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Vlad is $%.2f\n", 
						accountBalance);
					//if balance is negative set R and M to 1
					if (accountBalance <= 0.0f) {
						current->referenced = 1;
						current->modified = 1;
					}
					//otherwise set R to 1 and leave M alone
					else {
						current->referenced = 1;
					}
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
				//check for random condition to set all R bits to 0
				if (rand() % 20 == 0) {
					setRToZero(current);
				}
				//check for random condition to require an additional page
				if (rand() % 50 == 0) {
					printf("Page fault in thread Vlad\n");
					pageFault(current);
				}
			}
		}
		else {
			printf("Unexpected Error in Input File Occurred\n");
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
	pthread_mutex_lock(&linker);
	struct Node *current = (struct Node *) calloc(1, sizeof(struct Node));
	current = (struct Node *) arg;
	pthread_mutex_unlock(&linker);
	FILE *inFile = fopen("Frank.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Frank is $%.2f\n", 
						accountBalance);
					//if balance is negative set R and M to 1
					if (accountBalance <= 0.0f) {
						current->referenced = 1;
						current->modified = 1;
					}
					//otherwise set R to 1 and leave M alone
					else {
						current->referenced = 1;
					}
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
				//check for random condition to set all R bits to 0
				if (rand() % 20 == 0) {
					setRToZero(current);
				}
				//check for random condition to require an additional page
				if (rand() % 50 == 0) {
					printf("Page fault in thread Frank\n");
					pageFault(current);
				}
			}
		}
		else {
			printf("Unexpected Error in Input File Occurred\n");
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
	pthread_mutex_lock(&linker);
	struct Node *current = (struct Node *) calloc(1, sizeof(struct Node));
	current = (struct Node *) arg;
	pthread_mutex_unlock(&linker);
	FILE *inFile = fopen("Bigfoot.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Bigfoot is $%.2f\n", 
						accountBalance);
					//if balance is negative set R and M to 1
					if (accountBalance <= 0.0f) {
						current->referenced = 1;
						current->modified = 1;
					}
					//otherwise set R to 1 and leave M alone
					else {
						current->referenced = 1;
					}
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
				//check for random condition to set all R bits to 0
				if (rand() % 20 == 0) {
					setRToZero(current);
				}
				//check for random condition to require an additional page
				if (rand() % 50 == 0) {
					printf("Page fault in thread Bigfoot\n");
					pageFault(current);
				}
			}
		}
		else {
			printf("Unexpected Error in Input File Occurred\n");
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
	pthread_mutex_lock(&linker);
	struct Node *current = (struct Node *) calloc(1, sizeof(struct Node));
	current = (struct Node *) arg;
	pthread_mutex_unlock(&linker);
	FILE *inFile = fopen("Casper.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Casper is $%.2f\n", 
						accountBalance);
					//if balance is negative set R and M to 1
					if (accountBalance <= 0.0f) {
						current->referenced = 1;
						current->modified = 1;
					}
					//otherwise set R to 1 and leave M alone
					else {
						current->referenced = 1;
					}
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
				//check for random condition to set all R bits to 0
				if (rand() % 20 == 0) {
					setRToZero(current);
				}
				//check for random condition to require an additional page
				if (rand() % 50 == 0) {
					printf("Page fault in thread Casper\n");
					pageFault(current);
				}
			}
		}
		else {
			printf("Unexpected Error in Input File Occurred\n");
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
	pthread_mutex_lock(&linker);
	struct Node *current = (struct Node *) calloc(1, sizeof(struct Node));
	current = (struct Node *) arg;
	pthread_mutex_unlock(&linker);
	FILE *inFile = fopen("Gomez.in", "r");
	//read each line from file
	while ((read = getline(&line, &length, inFile)) != -1) {
		if (strncmp(line, "R", 1) == 0) {
			while (1) {
				//if we encounter W, we update balance and break
				if (strncmp(line, "W", 1) == 0) {
					pthread_mutex_lock(&locker);
					temp = (float) updateBalance / 100.00f;
					accountBalance += (float) temp;
					updateBalance = 0;
					temp = 0.0f;
					printf("Account balance after thread Gomez is $%.2f\n", 
						accountBalance);
					//if balance is negative set R and M to 1
					if (accountBalance <= 0.0f) {
						current->referenced = 1;
						current->modified = 1;
					}
					//otherwise set R to 1 and leave M alone
					else {
						current->referenced = 1;
					}
					pthread_mutex_unlock(&locker);
					sleep(1);
					break;
				}
				//otherwise we take each line update one at a time
				read = getline(&line, &length, inFile);
				temp = (float) atof(line) * 100.00f;
				updateBalance += (int) temp;
				//check for random condition to set all R bits to 0
				if (rand() % 20 == 0) {
					setRToZero(current);
				}
				//check for random condition to require an additional page
				if (rand() % 50 == 0) {
					printf("Page fault in thread Gomez\n");
					pageFault(current);
				}
			}
		}
		else {
			printf("Unexpected Error in Input File Occurred\n");
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
	pthread_mutex_init(&linker, NULL);
	
	//seed random generator with current time
	srand(time(0));
	
	//initialize and allocate memory for the six page nodes
	struct Node *head = (struct Node *) malloc(sizeof(struct Node));
	struct Node *second = (struct Node *) malloc(sizeof(struct Node));
	struct Node *third = (struct Node *) malloc(sizeof(struct Node));
	struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));
	struct Node *fifth = (struct Node *) malloc(sizeof(struct Node));
	struct Node *sixth = (struct Node *) malloc(sizeof(struct Node));
	
	//link the list in a circle
	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = sixth;
	sixth->next = head;
	
	//initialize bits in each node
	setBitsToZero(head);
	
	printf("Account balance initially is $%.2f\n", accountBalance);
	
	//spawn threads
	pthread_t tid[5];
	pthread_create(&(tid[0]), NULL, vlad, (void *) head);
	pthread_create(&(tid[1]), NULL, frank, (void *) second);
	pthread_create(&(tid[2]), NULL, bigfoot, (void *) third);
	pthread_create(&(tid[3]), NULL, casper, (void *) fourth);
	pthread_create(&(tid[4]), NULL, gomez, (void *) fifth);
	
	//let the threads run wild and free
	sleep(5);
	
	//detach threads
	for (int i = 0; i < 5; i++ ) {
		pthread_detach(tid[i]);
	}
	
	printf("Final account balance is $%.2f\n", accountBalance);
	
	//clean up
	pthread_mutex_destroy(&locker);
	pthread_mutex_destroy(&linker);

	return 0;
}
