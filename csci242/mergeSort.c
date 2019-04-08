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
	//define arrays to be sorted
	int *array1 = NULL;
	int *array2 = NULL;
	int *array3 = NULL;
	int *array4 = NULL;
	int size = 0; 
	int temp = 0;
	
	//define clock variables to measure runtimes
	clock_t start, end;
	double runtime1 = 0.0;
	double runtime2 = 0.0;
	double runtime3 = 0.0;
	double runtime4 = 0.0;
	
	//sanity check
	while (1) {
		printf("Enter the size (max 500,000) of the integer array");
		printf(" you wish to sort: ");
		scanf("%d",&size);
		if (size > 500000)
			printf("Array too large, please try again\n");
		else if (size < 0)
			printf("Array size undefined, please try again\n");
		else
			break;
	}
	
	//allocate memory for arrays
	array1 = malloc(size * sizeof(int));
	array2 = malloc((2 * size) * sizeof(int));
	array3 = malloc((3 * size) * sizeof(int));
	array4 = malloc((4 * size) * sizeof(int));
			
	//use current time as seed for random generator 
    srand(time(0)); 
  	
  	//fill arrays with random numbers between 0 and 999, inclusive
	for (int i = 0; i < size; i++) {
		temp = rand() %1000;
		array1[i] = temp;
	}
	for (int i = 0; i < 2 * size; i++) {
		temp = rand() %1000;
		array2[i] = temp;
	}
	for (int i = 0; i < 3 * size; i++) {
		temp = rand() %1000;
		array3[i] = temp;
	}
	for (int i = 0; i < 4 * size; i++) {
		temp = rand() %1000;
		array4[i] = temp;
	}
	//define max variables for mergeSort
	int max1 = size-1;
	int max2 = (2 * size) - 1;
	int max3 = (3 * size) - 1;
	int max4 = (4 * size) - 1;
	
	//start clock to measure runtime
	start = clock();
	//sort array
	mergeSort(array1, 0, max1);
	//end clock
	end = clock();
	runtime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	start = clock();
	mergeSort(array2, 0, max2);
	end = clock();
	runtime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	start = clock();
	mergeSort(array3, 0, max3);
	end = clock();
	runtime3 = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	start = clock();
	mergeSort(array4, 0, max4);
	end = clock();
	runtime4 = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//print sizes and runtimes
	printf("\nRuntime for array of size %d: %lf seconds\n",size,runtime1);
	printf("Runtime for array of size %d: %lf seconds\n",2*size,runtime2);
	printf("Runtime for array of size %d: %lf seconds\n",3*size,runtime3);
	printf("Runtime for array of size %d: %lf seconds\n",4*size,runtime4);

	return 0;
}

