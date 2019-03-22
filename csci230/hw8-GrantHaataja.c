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
	//make sure file is valid
	if (stream == NULL) {
		printf("File not found...\n");
		return 0;
	}
	//read each line and get work done
	else {
		while ((getline(&line, &length, *stream)) != -1) {
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
		FILE *stream) {
	//rewind the file to start at the beginning
	rewind(stream);
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
		word = strtok(line, " ,.\n");

		//enter do-while loop to create new nodes for each word and assign words
		do {
			//allocate memory for the word data for each node
			current->word = (char *) calloc(strlen(word)+1, sizeof(char));
			//assign the word of current node with the first word in file	
			
			/*if (strncmp(word, ",", 1) == 0) {
				current->punc = ',';
				printf("\nPunctuation!\n");
			}
			if (word == ".") {
				current->punc = '.';
			}*/
			
			strncpy(current->word, word, strlen(word));
			
			//allocate memory for next current node			
			current->next = (struct node*) malloc(sizeof(struct node));
			current = current->next;
		} while ((word = strtok(NULL, " ,.\n")) != NULL);
		//hide the body
		free(line);
		line = NULL;
	}
	return head;
}

//function to run through file again and add punctuation to poem linked list
void punctuate(struct node *head, struct node *current, int siz, FILE *stream) {
	//rewind the file to start at the beginning
	rewind(stream);
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;	
	//to store number of characters in each line	
	char *word;
	current = head;
	//mosey through each line of the file
	for (int i = 0; i < siz; i++) {
		getline(&line, &length, stream);
		//get the string token for the first non-word of the line
		word = strtok(line, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");
		//enter do-while loop to add punctuation to the nodes
		do {
			//assign the non-word characters to each node
			current->punc = (char) *word;
			
			current = current->next;
		} while ((word = strtok(NULL, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm")) != NULL);
		//hide the body
		free(line);
		line = NULL;	
	}	
}

//function to load data into codex
struct codex* load(struct codex *head, struct codex *current, int size, FILE *stream) {
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
		current->word1 = (char *) calloc(strlen(temp1)+1, sizeof(char));
		current->word2 = (char *) calloc(strlen(temp2)+1, sizeof(char));
		strncpy(current->word1, temp1, strlen(temp1));
		strncpy(current->word2, temp2, strlen(temp2));
		current->next = (struct codex*) malloc(sizeof(struct codex));
		current = current->next;
		free(line);
		line = NULL;
	}
	fclose(stream);
	return head;
}

void fixPoem(struct node *head, struct codex *headx) {
	int changed = 0;
	struct node *data = head;
	struct node *prev = head;
	struct codex *codex = headx;

	while(data->word) {
		changed = 0; 
		codex = headx;
		//go through the codex to replace words
		while(codex->word1 != NULL && changed == 0) {
			if(strcmp(codex->word1, data->word) == 0) {
				free(data->word);
				data->word = NULL;
				if(strcmp(codex->word2, "skip") == 0) {
					//link previous node to next node to unlink current node
					prev->next = data->next;
					//shoot the messenger
					free(data);
					//send word to client that the job is done
					changed = 1;
					//set current node to previous node to continue traversal
					data = prev;
				}
				else {
					data->word = calloc(strlen(codex->word2),sizeof(char));
					//copy the correct word from the codex
					strncpy(data->word, codex->word2, strlen(codex->word2));
					//send word to client that the job is done
					changed = 1;
				}
			}
			codex = codex->next;
		}
		prev = data;
		data = data->next;
	}
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
	char *temp;
	
	//count the number of lines in the data file
	dataSize = countLines(dataFile, &dstream);
	
	//count the number of lines in the codex file
	codexSize = countLines(codexFile, &cstream);
	
	//populate linked list with each word from the input file
	head = populate(head, current, dataSize, dstream);
	current = head;
	
	//run through the input file again to get punctuation for poem
	punctuate(head, current, dataSize, dstream);

	//populate codex from the file
	headx = load(headx, currentx, codexSize, cstream);
	currentx = headx;

	//traverse the poem linked list and replace words
	fixPoem(head, headx);
	
	//display results for checking purposes
	current = head;
	while (current->next) {
		printf("%s", current->word);
		printf("%c", current->punc);
		if (current->punc == ',' || current->punc == '.') {
			printf("\n");
		}
		current = current->next;
	}

	printf("\n");

}
