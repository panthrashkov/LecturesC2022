/*
 * main.c
 *
 *  Created on: 07.12.2012
 *      Author: admin
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int (*p)(const char *, const char *);
//реализация функции
void summa(short int a, short int b, int* summa){
	*summa =  a + b;
}

void change(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	// для корректной работы printf и scanf
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	// использование функции
	int c;
	summa(1,2,&c);
	printf("c равно %d  \n", c);
	int a = 9;
	int b = 3;
	change(&a,&b);
	printf("a равно %d b равно %d \n", a,b);

	return 0;
}

