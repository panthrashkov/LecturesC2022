/*
 * list_stack.c
 *
 *  Created on: 1 ���. 2022 �.
 *      Author: Alex
 */

#include "linked_list.h"

static node *stack_list = NULL;

void push(int elem){
	node * new_node = create_node(elem);
	new_node->data = elem;
	new_node->next = stack_list;
	stack_list = new_node;
}

int pop(void){

	if(stack_list != NULL){
		node * pelem = stack_list;
		int elem = stack_list ->data;
		stack_list = pelem-> next;
		remove_node(pelem);
		return elem;
	} else {
		// ���������� 0 ��� ��������� �� ������;
		return 0;
	}
}

int get_count(){
	int i = 0;
	node* tmp = stack_list;
	while(tmp != NULL){
		i++;
		tmp = tmp->next;
	}
	return i;
}
