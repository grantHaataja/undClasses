//CSci242 with Professor Emmanuel Grant
//Assignment III Merge-Sort
//Author: Grant Haataja ID: 1019828

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//merge function
void merge(int array[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	//create arrays L and R
	int L[n1], R[n2];
	int i, j, k;
	
	//copy data to temp arrays L and R
	for (i = 0; i < n1; i++) {
		L[i] = array[p + i];
		printf("Adding %d to temp array L\n", array[p+i]);
	}
	for (j = 0; j < n2; j++) {
		R[j] = array[q + 1 + j];
		printf("Adding %d to temp array R\n", array[q+1+j]);		
	}
	
	//merge temp arrays back into array
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}
	
	//copy remaining elements of L if there are any
	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	
	//copy the remaining elements of R if there are any
	while (j < n2) {
		array[k] = R[i];
		j++;
		k++;
	}
}

//merge-sort function
void mergeSort(int array[], int p, int r) {
	if (p < r) {
		int q = (p + (r-p)/2);
		mergeSort(array, p, q);
		mergeSort(array, q+1, r);
		merge(array, p, q, r);
	}
}

//display function
void display(int *array, int size) {
	

}

//Main Routine
int main(void) {
	//define array to be sorted
	int *unsorted = NULL;
	int size = 0; 
	int temp = 0;
	
	printf("Enter the size of the integer array you wish to sort: ");
	scanf("%d",&size);
	unsorted = calloc(size, sizeof(int));
	
	//use current time as seed for random generator 
    srand(time(0)); 
  
	for (int i = 0; i < size; i++) {
		temp = rand() %1000;
		printf(" %d ",temp);
		unsorted[i] = temp;
	}
  
	
	printf("\n\nUnsorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", unsorted[i]);
	}
	printf("\n\n");
	
	//sort array
	mergeSort(unsorted, 0, size-1);
	
	printf("\nSorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", unsorted[i]);
	}
	printf("\n");
	

	return 0;
}
