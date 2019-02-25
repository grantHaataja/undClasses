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
	//struct node *current = NULL;
	struct node *nodes[11];
	
	//allocate memory in heap for all nodes
	head = (struct node*) malloc(sizeof(struct node));
	//current = (struct node*) malloc(sizeof(struct node));
	//second = (struct node*) malloc(sizeof(struct node));
	
	//initialize head
	head->data = 0;
	//point head to first
	head->next = nodes[0];
	
	//populate linked list with 0 to 9
	for (int i = 0; i < 10; i++) {
			printf("Starting loop\n");
			nodes[i] = (struct node*) malloc(sizeof(struct node));
			nodes[i]->data = i;
			if (i < 9) {
				nodes[i]->next = nodes[i+1];
			}
			else {
				nodes[i+1] = NULL;
				nodes[i]->next = nodes[i+1];
			}
			printf("%d\n", nodes[i]->data);
	}

}

