#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {1,3,5,4,2};
float array_float[ARRAY_SIZE] = {1.,3.,5.,4.,2.};

int asc(void *pa, void *pb){
	return (*(int*) pa - *(int *)pb);
}

int desc(void *pa, void *pb){
	return (*(int*) pb - *(int *)pa);
}

int ascf(void *pa, void *pb){
	return (*(float*) pa - *(float *)pb);
}

void printArray(char *message, int *array, unsigned int arrayLength) {
	printf("%s ", message);
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

typedef int (*funp)(int);

//int (*fpp)(void *, void *);

void print(void * p, void* arg){
	node * node_pointer = (node *) p;
	printf("%d \n", node_pointer-> data);
}

void calc_total(void * p, void* arg){
	node * node_pointer = (node *) p;
	int *ptotal = (int*) arg;
	*ptotal += node_pointer -> data;
}

int doubleValue(int v){
	return 2*v;
}


int main(void){
	// ”казатели на void
	int x;

	void *p = &x;
	float y = 3.0;
	p =&y;
	printf("%p \n", p);
//	printf("%f \n", *p);
	printf("%d \n", *(int *)p);



	// ”казатели на функции
	funp fp;
	fp = doubleValue;
	p = fp;
	printf("double %d \n", ((funp) p)(5));
//	int (*fpp)(void *, void *);

	printArray("before sort \n", array, ARRAY_SIZE);
	qsort ( array , ARRAY_SIZE , sizeof ( int ) , asc );
	printArray("after sort asc \n", array, ARRAY_SIZE);
	qsort ( array , ARRAY_SIZE , sizeof ( int ) , desc );
	printArray("after sort desc \n", array, ARRAY_SIZE);
	qsort ( array_float , ARRAY_SIZE , sizeof ( float ) , ascf );
	printArray("after sort desc \n", array_float, ARRAY_SIZE);


	node * np = create_node(10);
	node * np1 = add_node(np, 20);
	node * np2 = add_node(np1, 30);

	apply(np2, print, NULL);

	int total = 0;
	apply(np2, calc_total, &total);
	printf("total %d", total);


	// сложные выражени€
	char(* foo)[5];
	// foo - это...
	// foo - это указатель на...
	// foo - это указатель на массив из п€ти...
	// foo - это указатель на массив из п€ти символов

	char* (*foo1)(char*);
	// foo1 - это...
	// foo1 - это указатель на...
	// foo1 - это указатель на функцию, принимающую указатель на символ...
	// foo1 - это указатель на функцию, принимающую указатель на символ, возвращающую указатель на...
	// foo1 - это указатель на функцию, принимающую указатель на символ, возвращающую указатель на символ

	char* (*(*foo2[5])(char*))[];
	// foo2 - это...
	// foo2 - это массив из 5...
	// foo2 - это массив из 5 указателей на...
	// foo2 - это массив из 5 указателей на функцию, принимающую указатель на символ...
	// foo2 - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на...
	// foo2 - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на массив из...
	// foo2 - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на массив из указателей на...
	// foo2 - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на массив из указателей на символ
}
