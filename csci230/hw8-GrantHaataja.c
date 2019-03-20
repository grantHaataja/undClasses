//Grant Haataja
//Assignment 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char *word;
	char punc;
	struct node *next;
};

struct codex {
	char *word1;
	char *word2;
	struct codex *next;
};

//function to count the number of lines in a file
int countLines(char *dataFile, FILE *(*stream)) {
	int size = 0;
	*stream = fopen(dataFile, "r");
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	ssize_t read = 0;
	//make sure file is valid
	if (stream == NULL) {
		printf("File not found...\n");
		return 0;
	}
	//read each line and get work done
	else {
		while ((read = getline(&line, &length, *stream)) != -1) {
			//increment size to count number of lines
			size++;
			//clean up the blood
			free(line);
			//hide the body
			line = NULL;
		}
	}
	return size;
}

//function to populate linked list with each word from the data file
struct node* populate(struct node *head, struct node *current, int size, 
		FILE *stream, char *dataFile) {
	//rewind the file to start at the beginning
	rewind(stream);
	int j = 0;	
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	char *word;
	//allocate memory for first node
	head = (struct node*) malloc(sizeof(struct node));
	current = head;
	//mosey through each line of the file
	for (int i = 0; i < size; i++) {
		getline(&line, &length, stream);
		//get the string token for the first word of the line
		word = strtok(line, " \n");

		//enter do-while loop to create new nodes for each word and assign words
		do {
			//allocate memory for the word data for each node
			current->word = (char *) calloc(strlen(word), sizeof(char));
			//assign the word of current node with the first word in file	
			if (word == ",") {
				current->punc = ',';
				printf("\nPunctuation!\n");
			}
			if (word == ".") {
				current->punc = '.';
			}
			strncpy(current->word, word, strlen(word));
			j++;
			
			//printf("%s ", current->word); //FIXME
			
			//allocate memory for next current node			
			current->next = (struct node*) malloc(sizeof(struct node));
			current = current->next;
		} while ((word = strtok(NULL, " \n")) != NULL);
		//hide the body
		free(line);
		line = NULL;
	}
	return head;
}

//function to load data into codex
struct codex* load(struct codex *head, struct codex *current, int size, FILE *stream, char *filename) {
	//rewind the file to start at the beginning
	rewind(stream);	
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	char *temp1;
	char *temp2;
	//allocate memory for first node
	head = (struct codex*) malloc(sizeof(struct codex));
	current = head;
	//mosey through each line of the file
	for (int i = 0; i < size; i++) {
		getline(&line, &length, stream);
		//get the string token for the first word of the line
		temp1 = strtok(line, " \n");
		temp2 = strtok(NULL, " \n");
		//allocate some memory
		current->word1 = (char *) calloc(strlen(temp1), sizeof(char));
		current->word2 = (char *) calloc(strlen(temp2), sizeof(char));
		strncpy(current->word1, temp1, strlen(temp1));
		strncpy(current->word2, temp2, strlen(temp2));
		current->next = (struct codex*) malloc(sizeof(struct codex));
		current = current->next;
		free(line);
		line = NULL;
	}
	return head;
}

int main(void) {
	//declare nodes
	struct node *head = NULL;
	struct node *current = NULL;
	struct codex *headx = NULL;
	struct codex *currentx = NULL;
	//declare hard-coded filenames for the pleasure of the TA
	char *dataFile = "hw8data.txt";
	char *codexFile = "hw8codex.txt";
	FILE *dstream;
	FILE *cstream;
	int dataSize = 0;
	int codexSize = 0;
	
	//count the number of lines in the data file
	dataSize = countLines(dataFile, &dstream);
	
	//count the number of lines in the codex file
	codexSize = countLines(codexFile, &cstream);
	
	//populate linked list with each word from the input file
	current = populate(head, current, dataSize, dstream, dataFile);

	//populate codex from the file
	currentx = load(headx, currentx, codexSize, cstream, codexFile);

	//display results for checking purposes
	while (current->next) {
		printf("%s\n", current->word);
		current = current->next;
	}
	//display results for checking purposes
	while (currentx->next) {
		printf("%s %s\n", currentx->word1,currentx->word2);
		currentx = currentx->next;
	}
	

}
