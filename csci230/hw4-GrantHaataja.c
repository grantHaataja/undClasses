//Grant Haataja
//Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vector function
char * vector(char *characters) {
	//allocate memory for any string
	int count = strlen(characters) + 1;
	characters = (char*) calloc(count, sizeof(char));

	return characters;
}

//Main Function
int main(void) {
	char *userInput;
	char *characters;
	char *hw4;
	char *temp;
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
	userInput = vector(userInput);
	while (1) {
		//get character one at a time
		userInput[i] = getchar();    	
		//check to break
		if (userInput[i] == '\n') {
			break;
		}	
		//call vector function to allocate memory
		characters = vector(characters);
		//add the user-entered char to string characters
		strcat(characters, userInput);
		i++;
	}
	//allocate memory and append characters to hw4
	hw4 = (char*) malloc((strlen(hw4) + strlen(characters) + 2) * sizeof(char));
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
