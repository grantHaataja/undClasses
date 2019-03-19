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
int countLines(char *dataFile) {
	int size = 0;
	FILE *stream = fopen(dataFile, "r");
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	ssize_t read = 0;
	//make sure file is valid
	if (stream == NULL) {
		printf("File not found...\n");
		exit(0);
	}
	//read each line and get work done
	else {
		while ((read = getline(&line, &length, stream)) != -1) {
			//increment size to count number of lines
			size++;
			//clean up the blood
			free(line);
			//hide the body
			line = NULL;
		}
	}
	//rewind(stream);	
	return size;
}

//function to populate linked list with each word from the data file
struct node populate(struct node *head, struct node *current, int size, FILE *stream, char *dataFile) {
	rewind(stream);
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	ssize_t read = 0;	
	//mosey through each line of the file
	for (int i = 0; i < size; i++) {
		getline(&line, &length, stream);
		//allocate memory for new node
		current = (struct node*) malloc(sizeof(struct node));
		//allocate memory for the word data for each node
		current->word = (char *) calloc(strlen(line), sizeof(char));
		//assign the word of current node with the first work in file
		current->word = strtok(line, " ");
	}
}

int main(void) {
	//declare nodes
	struct node *head = NULL;
	struct node *current = NULL;
	//declare hard-coded filenames for the pleasure of the TA
	char *dataFile = "hw8data.txt";
	char *codexFile = "hw8codex.txt";
	int size = 0;
	
	//count the number of lines in the file
	size = countLines(dataFile);
	printf("%d\n",size);
	
	//populate linked list with each word from the input file
	

}
