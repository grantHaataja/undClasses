//Grant Haataja
//Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vector function
char * vector(char *characters, int count) {
	//allocate memory for any string
	//int count = strlen(characters) + 1;
	printf("\nI'm in the function, about to allocate %d spaces of memory...\n", count); //FIXME delete
	
	characters = (char*) calloc(count, sizeof(char));
	printf("I'm in the function, just finished allocating %d spaces of memory...\n", count); //FIXME delete
	
	printf("\nI'm about to return %s.\n", characters); //FIXME delete
	return characters;//temp sring for userInput
}

//Main Function
int main(void) {
	char *userInput;
	char *characters;
	char *hw4;
	char *temp;
	int count = 1;
	hw4 = "HW 4 input: ";
	//allocate memory for temp string
	temp = (char*) malloc((strlen(hw4)) * sizeof(char));
	//copy hw4 initialization into temp string to use later in program
	strcpy(temp, hw4);
	//initialize characters to an empty string
	characters = "";
	//initialize userInput to an empty string
	userInput = "";
	printf("Enter characters: ");
	int i = 0;
	//allocate memory for userInput
	//userInput = vector(userInput);
	userInput = calloc(100, sizeof(char)); //FIXME delete
	printf("\nuserInput has %d spaces of memory...\n", strlen(userInput)); //FIXME delete
	while (1) {
		printf("\nITERATION %d\n", i); //FIXME delete
		//get character one at a time
		userInput[i] = getchar();
		printf("\nMy userInput is %s\n", userInput); //FIXME delete    	
		//check to break
		if (userInput[i] == '\n') {
			break;
		}	
		//call vector function to allocate memory
		characters = vector(characters, count);
		printf("\nI'm in the loop, just finished allocating memory\n"); //FIXME delete
		//add the user-entered char to string characters
		printf("\nArray (characters) has %d spaces of memory...\n", count); //FIXME delete
		printf("\nI'm about to cat %s onto my character array which is: %s\n", userInput, characters); //FIXME delete
		characters = strcat(characters, userInput);
		printf("\nArray (characters) is: %s.\n", characters); //FIXME delete
		//count how many characters are in array "characters" 
		count = strlen(characters) + 1;
		i++;
	}
	printf("\nI finished the loop!\n"); //FIXME delete
	//allocate memory and append characters to hw4
	hw4 = (char*) malloc((strlen(hw4) + strlen(characters) + 2) * sizeof(char));
	printf("\nHW4 String has %d characters in it...\n", strlen(hw4) + strlen(characters) + 2); //FIXME delete
	//cat the temp string to hw4 after the allocation of memory wiped it clean
	strcat(hw4, temp);
	//free memory for temp string
	free(temp);
	//cat the user-entered string "characters" to hw4
	strcat(hw4, characters);
	//free memory for characters string
	free(characters);
	//print hw4 as one final string to the terminal screen
	printf("\n%s\n", hw4);
	
	//free memory
	//free(userInput);
	//free(hw4);

	
	return 0;
}
