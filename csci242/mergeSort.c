//CSci242 with Professor Emmanuel Grant
//Assignment III Merge-Sort
//Author: Grant Haataja ID: 1019828

#include <stdio.h>
#include <stdlib.h>

//merge function
void merge(int *array, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	//create arrays L and R
	int L[n1], R[n2];
	int i, j, k;
	
	for (i = 1; i < n1; i++) {
		L[i] = array[p + i -1];
	}
	for (j = 1; j < n2; j++) {
		R[j] = array[q + j];
	}
	i = 1;
	j = 1;
	for (k = p; k < r; k++) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
	}

}

//merge-sort function
void mergeSort(int *array, int p, int r) {
	if (p < r) {
		int q = ((p + r) / 2);
		mergeSort(array, p, q);
		mergeSort(array, q+1, r);
		merge(array, p, q, r);
	}
}

//Main Routine
int main(void) {
	//define array to be sorted
	int *unsorted = NULL;
	int size = 0;
	
	printf("Enter the size of the integer array you wish to sort\n");
	scanf("%d",&size);
	unsorted = calloc(size+1, sizeof(int));
	printf("Enter integer values to fill the array\n");
	for (int i = 0; i < size; i++) {
		scanf("%d",&unsorted[i]);
	}
	
	printf("Unsorted array: [");
	for (int i = 0; i < size; i++) {
		printf("%d ", unsorted[i]);
	}
	printf("]\n");
	
	//sort array
	mergeSort(unsorted, unsorted[0], unsorted[size-1]);
	
	printf("Sorted array: [");
	for (int i = 0; i < size; i++) {
		printf("%d ", unsorted[i]);
	}
	printf("]\n");
	

	return 0;
}
