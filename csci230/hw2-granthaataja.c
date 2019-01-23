//Grant Haataja

//Includes
#include<stdio.h>
#include<stdlib.h>

//Functions
int getData(void) {
	//open file and such
	
}


//Main Routine
int main(void) {
	int userChoice = 0;
	//print out the menu
	while(1) {
		printf("1. Sort data by the float value & print high to low\n");
		printf("2. Sort data by the float value & print low to high\n");
		printf("3. Sort data by the int value & print high to low\n");
		printf("4. Sort data by the int value & print low to high\n");
		printf("5. Exit\n\n");
		
		//get input from the user
		scanf("%d", &userChoice);				
		//do task
		switch(userChoice) {
			case 1: 
				//call functions
			break;
			
			case 2:
				//call functions
			break;
			
			case 3: 
				//call functions
			break;
			
			case 4:
				//call functions
			break;
			
			case 5:
				exit(0);
			break;
			
			default: 
				printf("Unknown command, please enter an integer");
				printf(" between 1 and 5, inclusive.\n\n");
			break;
		}
		
		
	}
		
	

}
