//Grant Haataja

//Includes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//create structure
struct data {
	char model[42];
	float engine;
	int cost;
	char color[42];
} remember, *datum;
	
//count how many lines the file has
int fileSize(void) {
	int size = 0;
	char strTemp[100];
	float fltTemp;
	int intTemp;
	//open file
	FILE *stream;
	stream = fopen("./hw2.data", "r");
		if(stream == NULL) exit(0); //file not opened
		//count lines until the end of the file
		while(1) {
			fscanf(stream, "%s %f %d %s", strTemp, &fltTemp, &intTemp, strTemp);
			if(feof(stream)) {
				break;
			}
			size++;
		}
		fclose(stream);	
		return size;
}

//read file and store in an array of struct 
void getData(int size) {
	FILE *stream;
	stream = fopen("./hw2.data", "r");
		for(int i = 0; i < size; i++) {
			fscanf(stream, "%s %f %d %s", datum[i].model, &datum[i].engine, 
				&datum[i].cost, datum[i].color);
		}
	fclose(stream);
}

//function that swaps two elements
void swap(int i, int j) {
	remember = datum[i];
	datum[i] = datum[j];
	datum[j] = remember;
}

//partitions array using last element as pivot, moving smaller elements left
int partition(int start, int end) {
	int pivot = datum[end].engine; //set last element as pivot
	int i = (start - 1); //index of smaller element
	for(int j = start; j < end; j++) {
		//if current element is less than or equal to pivot
		if(datum[j].engine <= pivot) {
			i++; //increment index of smaller element
			swap(i,j);
		}
	}
	swap(i+1, end);
	return (i+1);
}

//quickSort data by float
void floatSort(int start, int end) {
	if(start < end) {
		//partition index
		int partIndex = partition(start, end);
		//separately sort elements before and after partition
		floatSort(start, partIndex - 1);
		floatSort(partIndex + 1, end);
	}
}

//quickSort data by int
void intSort(int size) {
	
}

//print data from high to low
void highToLow(int size) {
	for (int i = size - 1; i >= 0; i--) {
		printf("%s %1.1f %d %s\n", datum[i].model, datum[i].engine, 
			datum[i].cost, datum[i].color);
	}
}

//print data from low to high
void lowToHigh(int size) {
	for(int i = 0; i < size; i++) {
		printf("%s %1.1f %d %s\n", datum[i].model, datum[i].engine, 
			datum[i].cost, datum[i].color);
	}
}

//Main Routine
int main(void) {
	char userChoice = '0';
	int fileLines = 0;
	//print out the menu
	while(1) {
		printf("\n1. Sort data by the float value & print high to low\n");
		printf("2. Sort data by the float value & print low to high\n");
		printf("3. Sort data by the int value & print high to low\n");
		printf("4. Sort data by the int value & print low to high\n");
		printf("5. Exit\n\n");
		//get input from the user
		scanf("%c", &userChoice);				
		//do task
		switch(userChoice) {
			case '1': 
				fileLines = fileSize();
				datum = calloc(fileLines, sizeof(remember));
				getData(fileLines);
				floatSort(0, fileLines-1);
				highToLow(fileLines);
				free(datum);
				break;
			case '2':
				fileLines = fileSize();
				datum = calloc(fileLines, sizeof(remember));
				getData(fileLines);
				floatSort(0, fileLines-1);
				lowToHigh(fileLines);
				free(datum);
				break;
			case '3': 
				fileLines = fileSize();
				datum = calloc(fileLines, sizeof(remember));
				getData(fileLines);
				intSort(fileLines);
				highToLow(fileLines);
				free(datum);
				break;
			case '4':
				fileLines = fileSize();
				datum = calloc(fileLines, sizeof(remember));
				getData(fileLines);
				intSort(fileLines);
				lowToHigh(fileLines);
				free(datum);
				break;
			case '5':
				exit(0);
				break;
			/*default: 
				printf("Unknown command, please enter an integer");
				printf(" between 1 and 5, inclusive.\n\n");
				break;*/
		}
	}
}
