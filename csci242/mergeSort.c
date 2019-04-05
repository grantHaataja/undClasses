//CSci242 with Professor Emmanuel Grant
//Assignment III Merge-Sort
//Author: Grant Haataja ID: 1019828

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//merge function
void merge(int array[], int low, int mid, int high) {
	int n1, n2, i;
	int b[high];

	for(n1 = low, n2 = mid + 1, i = low; n1 <= mid && n2 <= high; i++) {
		if(array[n1] <= array[n2])
			b[i] = array[n1++];
		else
			b[i] = array[n2++];
	}
   
	while(n1 <= mid)    
		b[i++] = array[n1++];

	while(n2 <= high)   
		b[i++] = array[n2++];

	for(i = low; i <= high; i++)
		array[i] = b[i];
	}

void mergeSort(int array[], int low, int high) {
	if(low < high) {
		int mid = (low + high) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid+1, high);
		merge(array, low, mid, high);
	}
}

//Main Routine
int main(void) {
	//define array to be sorted
	int *unsorted = NULL;
	int size = 0; 
	int temp = 0;
	
	while (1) {
		printf("Enter the size (max 1,000,000) of the integer array");
		printf(" you wish to sort: ");
		scanf("%d",&size);
		if (size > 1000000)
			printf("Array too large, please try again\n");
		else if (size < 0)
			printf("Array size undefined, please try again\n");
		else
			break;
	}
	//allocate memory for array
	unsorted = malloc(size * sizeof(int));
		
	//use current time as seed for random generator 
    srand(time(0)); 
  
	for (int i = 0; i < size; i++) {
		temp = rand() %1000;
		printf(" %d ",temp);
		unsorted[i] = temp;
	}
	int max = size-1;
	
	printf("\n\nUnsorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", unsorted[i]);
	}
	printf("\n\n");
	
	//sort array
	mergeSort(unsorted, 0, max);
	
	printf("\nSorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", unsorted[i]);
	}
	printf("\n");
	
	return 0;
}

