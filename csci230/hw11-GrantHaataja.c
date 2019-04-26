//Grant Haataja
//Assignment 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Graph {
	char *word;
	struct Graph *arcs[10];
};

struct LinkedList {
	int index;
	struct LinkedList *next;
	struct Graph *child;
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
	//to temporarily store the start and end of arcs and the string cost
	char *arcStart, *arcEnd, *costString;
	//to store the cost associated with each arc
	int cost;
	//allocate memory for first node
	head = (struct node*) malloc(sizeof(struct node));
	current = head;
	int i = -1;
	int count = 0;
	//mosey through each line of the file
	for (i = 1; i < size; i++) {
		getline(&line, &length, stream);
		//get the string token for the first word of the line
		word = strtok(line, "\n");
		//check to see if the end of the establishments is here
		if (strcmp(word, "STOP") == 0) {
			free(line);
			line = NULL;
			break;
		}
		//allocate memory for the word data for each node
		current->word = (char *) calloc(strlen(word)+1, sizeof(char));
		//assign the word of current node with the establishment
		strncpy(current->word, word, strlen(word));
		//assign node its index number
		current->index = i;
		//assign each arc of the node to null
		for (int j = 0; j < 10; j++) {
			current->arcs[j] = NULL;
		}
		//allocate memory for next current node			
		current->next = (struct node*) malloc(sizeof(struct node));
		current = current->next;
		//hide the body
		free(line);
		line = NULL;
		count++;
	}
	//now continue parsing through file and adding all arcs to the proper nodes
	for (i = count; i < size; i++) {
		//get individual line to record arcs
		getline(&line, &length, stream);
		//check to see if arcs portion of file is reached, and break if true
		if (strcmp(line, "STOP STOP 0\n") == 0) {
			free(line);
			line = NULL;
			break;
		}
		printf("%s",line);
		//assign first destination of line to arcStart
		arcStart = strtok(line, " ");
		//assign second destination of line to arcEnd
		arcEnd = strtok(NULL, " ");
		//get the cost associated with arc as a string from line
		costString = strtok(NULL, "\n");
		//convert string cost associated with arc to an integer
		cost = atoi(costString);
		//now we need to parse through linked list of destinations and add the 
		//info for the arcs to each node
		current = head;
		int j = 0;
		while (current->next) {
			//if the node matches which arc line we are at
			if (strcmp(current->word, arcStart) == 0) {
				//find the next available spot in the array of arcs
				while (current->arcs[j] == 0 && j <= 10) {
					j++;
				}
				//copy the end destination to the corresponding starting point
				current->arcs[j] = calloc(strlen(arcEnd), sizeof(char));
				printf("Adding %s to the list of arcs\n", current->arcs[j]);
			}
			current = current->next;
		}
		
		free(line);
		line = NULL;	
	}
	printf("\nExitting function\n");
	return head;
}

//function to print and display to the screen 
void display(struct node *current) {
	while (current) {
		printf("Node %d: %s\n",current->index, current->word);
		for (int j = 0; j < 10; j++) {
			printf("Destination: %s\n",current->arcs[j]);
		}
		current = current->next;
	}
}


//Main Routine
int main(void) {
	//define fileName
	char *fileName = "hw111.data";
	FILE *stream;
	int size = 0;
	char *line = NULL;
	size_t length = 0;
	char *start;
	struct node *head = NULL;
	struct node *current = NULL;
	
	//count how many lines in file //TODO do we need this ??
	size = countLines(fileName, &stream);
	
	//populate linked list with each establishment from the input file
	head = populate(head, current, size, stream);
	current = head;

	//get last line of file to see where the journey begins
	getline(&line, &length, stream);
	start = strtok(line, "\n");
	free(line);
	line = NULL;
	fclose(stream);
	
	display(head);//FIXME
	
	

}
