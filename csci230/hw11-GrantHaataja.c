//Grant Haataja
//Assignment 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Graph {
	char *name;
	int cost[10];
	struct Graph *arcs[10];
};

struct LinkedList {
	int index;
	struct LinkedList *next;
	struct Graph *child;
};

//function to populate linked list with the establishments in the list
struct LinkedList* populate(struct LinkedList *head, struct LinkedList *current, 
		char *fileName,	FILE *stream) {
	//make sure file is valid and open file
	if ((stream = fopen(fileName, "r")) == NULL) {
		printf("\nFile not found...\n");
		return 0;
	}
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	char *name;
	
	
	//to temporarily store the start and end of arcs and the string cost
	char *arcStart, *arcEnd, *costString;
	
	
	//allocate memory for first node
	head = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	current = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	current = head;
	int i = -1;
	//mosey through each line of the file
	while (1) {
		i = 1;
		getline(&line, &length, stream);
		//get the string token for the first name of the line
		name = strtok(line, "\n");
		//check to see if the end of the establishments is here
		if (strcmp(name, "STOP") == 0) {
			free(line);
			line = NULL;
			break;
		}
		//assign node its index number
		current->index = i;
		//allocate memory for current LinkedList child
		current->child = (struct Graph*) malloc(sizeof(struct Graph));
		//allocate memory for the name of each graph node
		(current->child)->name = (char *) calloc(strlen(name)+1, sizeof(char));
		//assign the name of current child graph node with the establishment
		strncpy((current->child)->name, name, strlen(name));
		
		//assign each arc of the node to null
		for (int j = 0; j < 10; j++) {
			(current->child)->arcs[j] = malloc(sizeof(struct Graph));
			(current->child)->arcs[j] = NULL;
			(current->child)->cost[j] = 0;
		}
		
		//allocate memory for next current node			
		current->next = (struct LinkedList*) malloc(sizeof(struct LinkedList));
		current = current->next;
		//hide the body
		free(line);
		line = NULL;
		i++;
	}
	
	
	//now continue parsing through file and adding all arcs to the proper nodes
	while (getline(&line, &length, stream) != -1) {
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
		int cost = atoi(costString);
		
		//now we need to parse through linked list of destinations and add the 
		//info for the arcs to each node
		current = head;
		
		while (current->next) {
			int j = 0;
			//if name of child matches the arcStart
			if (strcmp((current->child)->name, arcStart) == 0) {
				//create a temp node to find the arcEnd
				struct LinkedList *temp = NULL;
				temp = (struct LinkedList*) malloc(sizeof(struct LinkedList));
				temp = head;
				
				//now find the one that matches arcEnd
				while (temp->next) {
					//if name of child matches the arcEnd
					if (strcmp((temp->child)->name, arcEnd) == 0) {
						//find the next available spot in arcs
						while ((current->child)->arcs[j] == NULL) {
							j++;
						}
						//assign temp->child to current->child arcs
						(current->child)->arcs[j] = temp->child;
					}
					temp = temp->next;
				}
				

			}
			current = current->next;
		}
		//free(temp);
		//temp = NULL;
		free(line);
		line = NULL;	
	}
	
	return head;
}

//function to print and display to the screen 
void display(struct LinkedList *current) {
	while (current->next) {
		printf("Node %d: %s\n",current->index, (current->child)->name);
		printf("\tPossible destinations: ");
		for (int j = 0; j < 10; j++) {
			printf("%s, ",(current->child)->arcs[j]->name);
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
	struct LinkedList *head = NULL;
	struct LinkedList *current = NULL;
	
	//populate linked list with each establishment from the input file
	head = populate(head, current, fileName, stream);
	current = head;
	
	printf("Successfully populated structures\n");

	//get last line of file to see where the journey begins
	getline(&line, &length, stream);
	start = strtok(line, "\n");
	free(line);
	line = NULL;	
	//fclose(stream);
	
	printf("\nNode %d: %s\n", current->index, (current->child)->name);
	printf("Possible destinations: %s", (current->child)->arcs[0]->name);

	//display(head);//FIXME
	
	

}
