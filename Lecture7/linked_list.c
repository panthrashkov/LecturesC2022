/*
 * linked_list.c
 *
 *  Created on: 31 ���. 2022 �.
 *      Author: Alex
 */
#include "linked_list.h"

// ��������� �������
node* create_node(int data){
	node * p = (node *) malloc(sizeof(node));
	if(p != NULL){
		p->data = data;
		p->next = NULL;
	}
	return p;
}

node* add_node(node * head, int payload){
	node * p = create_node(payload);
	if(p == NULL){
		return head;
	}
	p -> next = head;
	return p;
}

void remove_node(node * head){
	if(head != NULL){
		free(head);
	}
}

void apply (node * head, void (*fp) (void *, void *), void * arg){
	node * p = head;
	while(p != NULL){
		fp(p, arg);
		p = p->next;
	}
}



// ����� "���������" ������
static node* root = NULL;
static int listSize = 0;

static node* create_new_node(int data){
	node * p = (node *) malloc(sizeof(node));
	if(p != NULL){
		p->data = data;
		p->next = NULL;
	}
	listSize++;
	return p;
}

static inline int get_list_size(){
	return listSize;
}

void init(int data){
	root = create_new_node(data);
}

node* get_root(){
	return root;
}

void add_node_to_front(int payload){
	node * p = create_new_node(payload);
	if(p != NULL){
		p -> next = root;
		root = p;
	}
}

void add_node_to_back( int payload){
	node * p = create_new_node(payload);
	if(p != NULL){
		root -> next = p;
	}
}


