//Grant Haataja
//Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vector function
char * vector(char *characters) {
	//allocate memory for array characters
	int count = strlen(characters) + 1;
	printf("\n%d\n", count); //FIXME delete
	characters = calloc(count, sizeof(char));
	
	return characters;
}

//Main Function
int main(void) {
	char *userInput;
	char *characters;
	char *hw4;
	hw4 = "HW 4 input: ";
	characters = "";
	userInput = calloc(100, sizeof(char));
	//prompt user for input
	printf("Enter characters: ");
	int i = 0;
	printf("\n%s\n", userInput); //FIXME delete
	while (userInput[i] != '\n') {
    	//get character one at a time
		userInput[i] = getchar();	    
	    printf("\n%s\n", characters); //FIXME delete
	    printf("WHADDAFUQ\n"); //FIXME delete
		//call vector function to allocate memory
		characters = vector(characters);
		//add the user-entered char to string charaters
		strcat(characters, userInput);
		i++;
	}
	
	printf("%s", characters); //FIXME delete
	printf("YEET!"); //FIXME delete
	
	return 0;
}
