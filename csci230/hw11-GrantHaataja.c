//Grant Haataja
//Assignment 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Graph {
	char *name;
	int cost[10];
	int numArcs;
	struct Graph *arcs[10];
};

struct LinkedList {
	struct LinkedList *next;
	struct Graph *child;
};


//function to populate linked list with the establishments in the list
struct LinkedList* populate(struct LinkedList *head, struct LinkedList *current, 
		char *fileName,	FILE *(*stream)) {
	//make sure file is valid and open file
	if ((*stream = fopen(fileName, "r")) == NULL) {
		printf("\nFile not found...\n");
		return 0;
	}
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	char *name;	
	//allocate memory for first node
	head = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	current = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	current = head;
	
	//mosey through each line of the file
	while (1) {
		getline(&line, &length, *stream);
		//get the string token for the first name of the line
		name = strtok(line, "\n");
		//check to see if the end of the establishments is here
		if (strcmp(name, "STOP") == 0) {
			free(line);
			line = NULL;
			break;
		}
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
		(current->child)->numArcs = 0;
		//allocate memory for next current node			
		current->next = (struct LinkedList*) malloc(sizeof(struct LinkedList));
		current = current->next;
		//hide the body
		free(line);
		line = NULL;
	}
	return head;
}


//function to actually add each possible arc for each graph node
int addArc(struct LinkedList* head, char *arcStart, char *arcEnd, int cost) {
	struct LinkedList *current = NULL;
	current = head;
	
	while (current->next) {
		int j = 0;
		//if name of child matches the arcStart
		if (strcmp((current->child)->name, arcStart) == 0) {
			//create a temp node to find the arcEnd
			struct LinkedList *temp = NULL;
			//temp = (struct LinkedList*) malloc(sizeof(struct LinkedList));
			temp = head;
			
			//now find the one that matches arcEnd
			while (temp->next) {
				//if name of child matches the arcEnd
				if (strcmp((temp->child)->name, arcEnd) == 0) {
					//assign temp->child to current->child arcs
					(current->child)->arcs[(current->child)->numArcs] = temp->child;
					//add cost associated with arc
					(current->child)->cost[(current->child)->numArcs] = cost;
					//update index
					(current->child)->numArcs++;
					return 1;
				}
				temp = temp->next;
			}
		}
		current = current->next;
	}
	return 0;
}
	

//function to handle and store possible arcs in an array for each graph node
void arcs(struct LinkedList *head, struct LinkedList *current, FILE *stream) {
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to temporarily store the start and end of arcs and the string cost
	char *arcStart, *arcEnd, *tmp;
	
	//now continue parsing through file and adding all arcs to the proper nodes
	while (getline(&line, &length, stream) != -1) {
		//check to see if arcs portion of file is reached, and break if true
		if (strcmp(line, "STOP STOP 0\n") == 0) {
			free(line);
			line = NULL;
			break;
		}
		//assign first destination of line to arcStart
		tmp = strtok(line, " ");
		arcStart = (char*) calloc(strlen(tmp), sizeof(char));
		strcpy(arcStart, tmp);
		//assign second destination of line to arcEnd
		tmp = strtok(NULL, " ");
		arcEnd = (char*) calloc(strlen(tmp), sizeof(char));
		strcpy(arcEnd, tmp);
		//get the cost associated with arc as a string from line
		tmp = strtok(NULL, "\n");
		//convert string cost associated with arc to an integer
		int cost = atoi(tmp);
		//now call addArc to finish the job
		int status = addArc(head, arcStart, arcEnd, cost);
		//free stuff to start the loop again
		free(arcStart);
		free(arcEnd);
		free(line);
		arcStart = NULL;
		arcEnd = NULL;
		line = NULL;	
	}
}	


//function to free all dynamically allocated memory
void FREE(struct LinkedList *current) {
	struct LinkedList *temp = NULL;
	while (current->next) {
		free((current->child)->name);
		free(current->child);
		temp = current->next;
		free(current);
		current = temp;
	}
}


//function to find the starting point of the journey
struct Graph* getStart(struct LinkedList *current, FILE *stream) {
	char *line = NULL;
	size_t length = 0;
	char *start, *temp;
	
	//get last line of file
	getline(&line, &length, stream);
	temp = strtok(line, "\n");
	start = (char*) calloc(strlen(temp), sizeof(char));
	//assign last destination to start
	strcpy(start, temp);
	free(line);
	line = NULL;
	
	//now find which node to start at
	while (current->next) {
		if (strcasecmp(start, (current->child)->name) == 0) {
			//found it
			free(start);
			return current->child;
		}
		current = current->next;
	}
	free(start);
	printf("Starting location not found. Exitting now.\n");
	return 0;
}


//function to implement the random drunkard's walk and count the cost
void drunkWalk(struct Graph* start) {
	//define random numbers for the drunken algorithm
	int random = 0;
	int next = 0;
	//use current time as seed for random generator
	srand(time(0));
	//variable to accumulate total cost
	int tc = 0;
	struct Graph *current = start;
	
	//start the walk
	while (strcasecmp(current->name, "home") != 0) {
		printf("Location: %s with a cost of %d\n", current->name, tc);
		//check to see if we are stuck
		if (current->numArcs == 0) {
			printf("\n******** DRUNKEN WALK COMPLETE ********\n");
			printf("We cannot get home. The total cost is %d\n", tc);
			printf("We started at %s and ended at %s\n", start->name, current->name);
			return;
		}
		
		next = (int) (rand() % current->numArcs);
		tc = tc + current->cost[next];
		current = current->arcs[next];
	}
	printf("Location: %s with a cost of %d\n", current->name, tc);
	printf("\n******** DRUNKEN WALK COMPLETE ********\n");	
	printf("We are home! The total cost is %d\n", tc);
	printf("We started at %s and ended at %s\n", start->name, current->name);
	return;
}


//Main Routine
int main(void) {
	//define fileName to be used for the journey
	char *fileName = "hw11.data";
	
	FILE *stream;
	struct LinkedList *head = NULL;
	struct LinkedList *current = NULL;
	struct Graph *start = NULL;
	
	//populate linked list with each establishment from the input file
	head = populate(head, current, fileName, &stream);
	current = head;
	
	//add the possible arcs to each graph node
	arcs(head, current, stream);

	//get last line of file to see where the journey begins
	start = getStart(head, stream);
	fclose(stream);
	
	//do the walk of shame
	drunkWalk(start);

	//clean up the mess
	FREE(head);
}
