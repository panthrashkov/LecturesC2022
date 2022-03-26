#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int  stack_buffer[100];
int  itop  = 0;

int get_count(){
	return itop;
}

void push(int elem){
	stack_buffer[itop++] = elem;
}

int pop(void){
	if(itop > 0) {
		return stack_buffer[--itop];
	} else {
		return 0;
	}
}

typedef struct node {
	int data;
	struct node * next;
}node;

node *stack_list = NULL;

node* create_new_node(int data){
	node * p = (node *) malloc(sizeof(node));
	if(p != NULL){
		p->data = data;
		p->next = NULL;
	}
	return p;
}

void pushList(int elem){
	node * new_node = create_new_node(elem);
	new_node->data = elem;
	new_node->next = stack_list;
	stack_list = new_node;
}

int popList(void){
	if(stack_list != NULL){
		node * pelem = stack_list;
		int elem = stack_list ->data;
		stack_list = pelem-> next;
		free(pelem);
		return elem;
	} else {
		// возвращаем 0 или сообщение об ошибке;
		return 0;
	}
}

int getCountList(){
	int i = 0;
	node* tmp = stack_list;
	while(tmp != NULL){
		i++;
		tmp = tmp->next;
	}
	return i;
}


int main(void){
	roundf(3.34);
	push(1); push(2); push(3);
	printf("pop %d \n", pop());
	printf("pop %d \n", pop());
	printf("count in stack %d \n", get_count());

	pushList(3);pushList(2);pushList(1);pushList(0);
	printf("popList %d \n", popList());
	printf("popList %d \n", popList());
	printf("count in stack %d \n", getCountList());
	printf("popList %d \n", popList());
	printf("count in stack %d \n", getCountList());

}
