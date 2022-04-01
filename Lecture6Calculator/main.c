#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "stack.h"
#include "queue.h"

#define OPERATORS_SIZE  4
#define INPUT_SIZE  8

const operator EMPTY = {'0', -1};

operator operators[OPERATORS_SIZE] =  { {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};

operator get_operator(char s){
	for(int i = 0; i < OPERATORS_SIZE; i++){
		if(operators[i].symbol == s){
			return operators[i];
		}
	}
	return EMPTY;
}

char input_expression[INPUT_SIZE] = "A+B*C-D";
char output[INPUT_SIZE];

int is_empty(const operator *o) {
	return o->symbol == EMPTY.symbol && o->priority == EMPTY.priority;
}

int main(void){
	// Заполняем входную очередь
   for (int i = 0; i < INPUT_SIZE; i++){
	  enqueue(input_expression[i], INPUT);
   }
   // Цикл по количеству символов
   for (int i = 0; i < INPUT_SIZE; i++){
	  char s = dequeue(INPUT);
	  printf("%c ", s);
	  operator o = get_operator(s);
	  if (is_empty(&o)) {
		  enqueue(s, OUTPUT);
	  } else {
		  operator stack_operator = pop();
		  while(!is_empty(&stack_operator) && stack_operator.priority >= o.priority){
			  enqueue(stack_operator.symbol, OUTPUT);
			  stack_operator = pop();
		  }
		  push(stack_operator);
		  push(o);
	  }
   }
   operator stack_operator = pop();
   while(!is_empty(&stack_operator)){
	   enqueue(stack_operator.symbol, OUTPUT);
	   stack_operator = pop();
   }
   printf("------> ");
   for (int i = 0; i < INPUT_SIZE; i++){
	  printf("%c ", dequeue(OUTPUT));
   }
}
