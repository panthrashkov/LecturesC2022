/*
 * array_stack.c
 *
 *  Created on: 25 мар. 2022 г.
 *      Author: Alex
 */


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
