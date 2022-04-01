/*
 * stack.h
 *
 *  Created on: 25 мар. 2022 г.
 *      Author: Alex
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct{
	char symbol;
	int priority;
}operator;

void push(operator);
operator pop();
int get_count();


#endif /* STACK_H_ */
