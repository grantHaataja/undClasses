//Grant Haataja
//Assignment 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char *word;
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
		word = strtok(line, " ");

		//enter do-while loop to create new nodes for each word and assign words
		do {
			//allocate memory for the word data for each node
			current->word = (char *) calloc(strlen(word), sizeof(char));
			//assign the word of current node with the first word in file	
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

int main(void) {
	//declare nodes
	struct node *head = NULL;
	struct node *current = NULL;
	//declare hard-coded filenames for the pleasure of the TA
	char *dataFile = "hw8data.txt";
	char *codexFile = "hw8codex.txt";
	FILE *stream;
	int size = 0;
	
	//count the number of lines in the file
	size = countLines(dataFile, &stream);
	
	//populate linked list with each word from the input file
	current = populate(head, current, size, stream, dataFile);

	//display results for checking purposes
	while (current->next) {
		printf("%s\n", current->word);
		current = current->next;
	}
	

}
