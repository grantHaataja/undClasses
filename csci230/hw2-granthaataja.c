//Grant Haataja

//Includes
#include<stdio.h>
#include<stdlib.h>

//Functions
struct getData(void) {
	//create structure
	struct data {
		char model[42];
		float engine;
		int cost;
		char color[42];
	} datum[100];
	
	//open file
	FILE *stream;
	stream = fopen("hw2.data", "r");
	if(stream == NULL) exit(0); //file not opened
	//scan in data from file
	for(int i=0; i < 8; i++) {
		fscanf("%s %f %d %s",&datum[i]);
		fprintf("%s %f %d %s",&datum[i]);
	}
	return datum;
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
		
		//scan in data from file
		getData();
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
