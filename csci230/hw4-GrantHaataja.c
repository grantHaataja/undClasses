//Grant Haataja
//Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vector function
char * vector(char *characters) {
	//allocate memory for array characters
	int count = strlen(characters);
	printf("\n%d", count); //FIXME delete
	characters = calloc(count, sizeof(char));

}

//Main Function
int main(void) {
	char *userInput;
	char *characters;
	char *hw4;
	hw4 = "HW 4 input: ";
	//prompt user for input
	printf("Enter characters: ");
	vector(characters);
	/*while (1); {
		printf("REALLY?"); //FIXME delete
		//get character one at a time
	    //userInput[0] = getchar();
	    printf("%s", characters); //FIXME delete
	    printf("WHADDAFUQ"); //FIXME delete
		//call vector function to allocate memory
		vector(characters);
		//add the user-entered char to string charaters
		strcat(userInput, characters);
	}*/
	
	printf("%s", characters); //FIXME delete
	
	return 0;
}
