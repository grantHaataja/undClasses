//Grant Haataja
//Assignment 7

#include<stdlib.h>
#include<stdio.h>

//structure for linked list
typedef struct node {
	int  data;
	struct node *next;
}link;

//search function for linked list
link *searchList(int value, link *head) {
	while (head != NULL) {
		if (head->data == value) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}

//Main
int main(void) {
	//declare nodes
	struct node *head = NULL;
	struct node *current = NULL;
	int search = 0;
	
	//populate linked list with 0 to 9
	for (int i = 9; i >= 0; i--) {
		//declare memory space for a new node in the heap
		current = (struct node*) malloc(sizeof(struct node));
		//set data value for node to i (starting with 9)
		current->data = i;
		//set next node to head as we traverse downward through links
		current->next = head;
		//assign current to head and repeat process
		head = current;
		//we end with the head as the current node, with value of 0
	}
	//display results with the following code from hw7.txt
	while (current) {
		printf("%d\n", current->data);
		current = current->next;
	}
	
	//prompt user to search for a value
	printf("Enter a value to search for: ");
	scanf("%d", &search);
	//sanity check
	if (searchList(search, head) == NULL) {
		printf("Value not found. Exitting program...\n");
	}
	//search for value and print it
	else {
		printf("[%d %d]\n", search, searchList(search, head)->data);
	}

	//free all nodes
	while (current) {
		free(current);
		//free(head);
		current = current->next;
		//head = head->next;	
	}
	free(head); //TODO check if this is a problem on mint
	//set nodes to null to hide the evidence
	current = NULL;
	head = NULL;
	
	return 0;
}

