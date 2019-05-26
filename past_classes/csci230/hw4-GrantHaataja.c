//Grant Haataja
//Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vector function
char * vector(char *characters, int count) {
	char * ptr;
	//allocate memory for any string
	ptr = (char*) calloc(count+1, sizeof(char));
	//copy memory into ptr to return to Main
	memcpy(ptr, characters, count);
	return ptr;
}

//Main Function
int main(void) {
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
	printf("Enter characters: ");
	int i = 0;
	//allocate memory for characters
	characters = calloc(2, sizeof(char)); 
	while (1) {
		//get character one at a time
		characters[i] = getchar();		  	
		//check to break
		if (characters[i] == '\n') {
			break;
		}	
		//call vector function to allocate memory
		characters = vector(characters, count);
		//count how many characters are in array "characters" 
		count = strlen(characters) + 1;
		i++;
	}
	//allocate memory and append characters to hw4
	hw4 = (char*) malloc((strlen(hw4) + count + 2) * sizeof(char));
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
	free(hw4);
	
	return 0;
}

