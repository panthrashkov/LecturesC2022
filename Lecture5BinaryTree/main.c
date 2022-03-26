/*
 * main.c
 *
 *  Created on: 18 мар. 2022 г.
 *      Author: Alex
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 7

typedef struct tnode{
	int data;
	struct tnode * left;
	struct tnode * right;
}tnode;

struct tnode * create_new_tnode(int data){
	struct tnode * p = (struct tnode *) malloc(sizeof(struct tnode)*1);
	p-> data = data;
	p-> left = NULL;
	p-> right = NULL;
	return p;
}

struct tnode * add_node(tnode * root, int data){
	if (root == NULL){
		return create_new_tnode(data);
	} else if (data < root -> data){
		root -> left = add_node(root -> left, data);
	} else {
		root -> right = add_node(root -> right, data);
	}
	return root;
}

void print(tnode * root){
	if(root -> left != NULL){
		print(root->left);
	}
	printf("data value -> %d \n", root->data);
	if(root -> right != NULL){
		print(root-> right);
	}
}


void printSorted(tnode * root);

int main(void) {
	printf("Begin \n");

	int array[ARRAY_SIZE] = {10,3,6,7,1,2,5};
	tnode * root = NULL;

	for(int i = 0; i < ARRAY_SIZE; i++){
		root = add_node(root, array[i]);
	}

	print(root);

	return EXIT_SUCCESS;
}

void printSorted(tnode * root){
	if(root -> left != NULL){
		printSorted(root->left);
	}
	printf("data value -> %d \n", root->data);
	if(root -> right != NULL){
		printSorted(root-> right);
	}
}



