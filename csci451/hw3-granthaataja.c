/*CSCI 451 - Assignment 3
Grant Haataja

Compile with: gcc hw3-granthaataja.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

//function to count the number of lines in a file
int countWords(char *dataFile, FILE *(*stream)) {
	int size = 0;
	*stream = fopen(dataFile, "r");
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	char *word;
	//make sure file is valid
	if (stream == NULL) {
		printf("File not found...\n");
		return 0;
	}
	//read each line and get work done
	else {
		while ((getline(&line, &length, *stream)) != -1) {
			//get the string token for the first word of the line
			word = strtok(line, " :;></?\\|[]{}+=--()*&^%$#@!`~\",.\n");
			//enter do-while loop to count number of words in file
			do {
				//increment size to count number of words
				size++;
			} while ((word = 
				strtok(NULL, " :;></?\\|[]{}+=--()*&^%$#@!`~\",.\n")) != NULL);
			//clean up the blood
			free(line);
			//hide the body
			line = NULL;
		}
	}
	return size;
}

//function to populate dynamic array with all the words from the file
void populate(char **allWords, int size, FILE *stream) {
	//rewind the file to start at the beginning
	rewind(stream);
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	char *word;
	int i = 0;
	int c = 0;
	char ch;
	//go through each line of the file
	while ((getline(&line, &length, stream)) != -1) {
		//get the string token for the first word of the line
		word = strtok(line, " :;></?\\|[]{}+=--()*&^%$#@!`~\",.\n");
		//enter do-while loop to count number of words in file
		do {
			//allocate memory for the size of each individual word in the file
			allWords[i] = (char *) malloc(sizeof(char) * (strlen(word)+1));
			//change the word to lowercase
			while (word[c]) {
				ch = word[c];
				word[c] = tolower(ch);
				c++;
			}
			c = 0;
			//copy the word into the array
			strncpy(allWords[i], word, strlen(word));
			i++;		
		} while ((word = 
			strtok(NULL, " :;></?\\|[]{}+=--()*&^%$#@!`~\",.\n")) != NULL);
		//clean up the blood
		free(line);
		//hide the body
		line = NULL;
	}
	//close file
	fclose(stream);
}

void *easyThread(void *arg) {
	int countEasy = 0;
	int i = 0;
	char *easy = "easy";
	char **totalWords = ((char **) arg);
	
	while (totalWords[i]) {
		if (strncmp(totalWords[i], easy, strlen(totalWords[i])) == 0) {
			countEasy++;
		}
		i++;
	} 
	printf("Easy Occurences: %d\n", countEasy);
}

void *polarThread(void *arg) {
	int countPolar = 0;
	int j = 0;
	char *polar = "polar";
	char **totalWords = ((char **) arg);
	
	while (totalWords[j]) {
		if (strncmp(totalWords[j], polar, strlen(totalWords[j])) == 0) {
			countPolar++;
		}
		j++;
	}
	printf("Polar Occurences: %d\n", countPolar);
}

int main(int argc, char** argv) {
	//declare dynamic array to hold all the words in the file
	char **allWords;
	
	//fetch the data file
	system("wget -q http://undcemcs01.und.edu/~ronald.marsh/CLASS/CS451/hw3-data.txt");

	//count the number of lines in the file
	FILE *fstream;
	int numWords = countWords("hw3-data.txt", &fstream);
	
	//allocate memory for the number of words in the file
	allWords = (char **) malloc(sizeof(char*) * (numWords + 1));
	
	//call function to load words from file into array
	populate(allWords, numWords, fstream);
	
	//create two threads and call them to search for their specified words
	pthread_t tid;
	pthread_create(&tid, NULL, easyThread, ((void *)allWords));
	pthread_create(&tid, NULL, polarThread, ((void *)allWords));
	pthread_join(tid, NULL);
	
	//clean up
	free(allWords);
	system("unlink hw3-data.txt");

	return 0;
}
