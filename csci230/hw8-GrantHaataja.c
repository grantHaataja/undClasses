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
struct node populate(struct node *head, struct node *current, int size, 
		FILE *stream, char *dataFile) {
	//rewind the file to start at the beginning
	rewind(stream);
	int j = 0;	
	//string variable to hold each individual line
	char *line = NULL;
	size_t length = 0;
	//to store number of characters in each line	
	ssize_t read = 0;	
	//mosey through each line of the file
	for (int i = size; i > 0; i--) {
		getline(&line, &length, stream);
		//allocate memory for new node
		current = (struct node*) malloc(sizeof(struct node));
		//allocate memory for the word data for each node
		int length = strlen(line);
		current->word = (char *) calloc(length, sizeof(char));
		//assign the word of current node with the first work in file
		current->word = strtok(line, " ");
		printf("%s ", current->word); //FIXME
		//set next node to head as we traverse downward through links
		current->next = head;
		//assign current to head and repeat process
		head = current;
		//enter do-while loop to create new nodes for each word and assign words
		while (current->word) {
			//allocate memory for new current node			
			current = (struct node*) malloc(sizeof(struct node));
			//allocate memory for word to be assigned to new current node
			current->word = (char *) calloc(length, sizeof(char));
			//assign next word in line to new current node
			if (current->word = strtok(NULL, " ")) {
				j++;
				printf("%s ", current->word); //FIXME
				//set next node to head as we traverse downward through links
				current->next = head;
				//assign current to head and repeat process
				head = current;
			}
		} 
		current->next = head;
		head = current;
		free(line);
		line = NULL;
		//printf("\n");
	}
	printf("%d\n",j);
	printf("\n NOW LET'S TRY TO PRINT THE POEM \n");
	//current = head;
	while (current) {
		printf("%s\n", current->word);
		current = current->next;
	}
	
	return *current;
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
	printf("%d\n",size);
	
	//populate linked list with each word from the input file
	*current = populate(head, current, size, stream, dataFile);

	//display results for checking purposes
	//current = head;
	while (current) {
		printf("%s\n", current->word);
		current = current->next;
	}
	

}
