//Grant Haataja
//Assignment 7

#include<stdlib.h>
#include<stdio.h>

//structure for linked list
struct node {
	int  data;
	struct node *next;
};

//search function for linked list
//link *searchList(int value, link *head) {

//}

//Main
int main(void) {
	//declare nodes
	struct node *head = NULL;
	struct node *current = NULL;
	
	//allocate memory in heap for all nodes
	head = (struct node*) malloc(sizeof(struct node));
	current = (struct node*) malloc(sizeof(struct node));
	
	//initialize head
	head->data = 0;
	//point head to first
	//head->next = current;
	current = head;
	
	//populate linked list with 0 to 9
	for (int i = 0; i < 10; i++) {
		printf("i = %d\n",i);
		current->data = i;
		printf("current->data = %d\n",current->data);
		current->next = (struct node*) malloc(sizeof(struct node));		
		if (current->next == NULL)
			printf("current->next = NULL");
		current = current->next;
	}
	
	//display results with the following code from hw7.txt
	while (current) {
		printf("%d\n", current->data);
		current = current->next;
	}

}

