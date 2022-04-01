/*
 * array_stack.c
 *
 *  Created on: 25 мар. 2022 г.
 *      Author: Alex
 */
#include "stack.h"
#include <stddef.h>

operator stack_buffer[100];
int  itop  = 0;
extern const operator EMPTY;

int get_count(){
	return itop;
}

void push(operator elem){
	stack_buffer[itop++] = elem;
}

operator pop(void){
	if(itop > 0) {
		return stack_buffer[--itop];
	} else {
		return EMPTY;
	}
}
