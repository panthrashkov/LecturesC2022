/*
 * main.c
 *
 *  Created on: 18 мар. 2022 г.
 *      Author: Alex
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node1 {
	int data;
	struct node1 * next;
};

typedef struct node {
	int data;
	struct node * next;
}node;

node* create_new_node(int data){
	node * p = (node *) malloc(sizeof(node));
	if(p != NULL){
		p->data = data;
		p->next = NULL;
	}
	return p;
}

node* add_node_to_front(node * head, int payload){
	node * p = create_new_node(payload);
	if(p == NULL){
		return head;
	}
	p -> next = head;
	return p;
}

int main(void) {
	struct node1 a;

	node* b = create_new_node(10);
	printf("node payload %d \n", b-> data);

	node* head = add_node_to_front(b, 100);

	printf("node payload %d \n", head-> data);
	free(b);
	printf("node payload %d \n", head-> next->data);
	free(head);

	return EXIT_SUCCESS;
}



