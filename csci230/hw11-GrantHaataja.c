//Grant Haataja
//Assignment 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char *word;
	int index;
	struct node *next;
};

//function to count lines in file
int countLines(char *fileName, FILE *(*stream)) {
	//variable for number of lines
	int size = 0;
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//check if file is valid
	if ((*stream = fopen(fileName, "r")) == NULL) {
		printf("\nFile not found...\n");
		return 0;
	}
	else {
		while ((getline(&line, &length, *stream)) != -1) {
			//increment size to count number of lines
			size++;
			//free line variable and set to null
			free(line);
			line = NULL;
		}
		//return number of lines
		return size;
	}
}

//function to populate linked list with the establishments in the list
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
	int i = 0;
	//mosey through each line of the file
	for (i = 0; i < size; i++) {
		getline(&line, &length, stream);
		//get the string token for the first word of the line
		word = strtok(line, "\n");
		//check to see if the end of the establishments is here
		if (strcmp(word, "STOP") == 0) {
			break;
		}
		//allocate memory for the word data for each node
		current->word = (char *) calloc(strlen(word)+1, sizeof(char));
		//assign the word of current node with the establishment
		strncpy(current->word, word, strlen(word));
		//assign node its index number
		current->index = i;
		//allocate memory for next current node			
		current->next = (struct node*) malloc(sizeof(struct node));
		current = current->next;
		//hide the body
		free(line);
		line = NULL;
	}
	return head;
}

//function to print and display to the screen 
void display(struct node *current) {
	while (current) {
		printf("Node %d: %s\n",current->index, current->word);
		current = current->next;
	}
}


//Main Routine
int main(void) {
	//define fileName
	char *fileName = "hw111.data";
	FILE *stream;
	int size = 0;
	struct node *head = NULL;
	struct node *current = NULL;
	
	//count how many lines in file
	size = countLines(fileName, &stream);
	printf("There are %d lines in file\n",size);
	
	//populate linked list with each establishment from the input file
	head = populate(head, current, size, stream);
	current = head;
	
	display(head);//FIXME

}
