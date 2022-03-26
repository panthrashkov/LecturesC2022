/*
 * main.c
 *
 *  Created on: 07.12.2012
 *      Author: admin
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// неправильная реализация функции обмена значений переменных
void wrong_change(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}
//реализация функции обмена через указатели
void change(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// более точная (безопасная) реализация функции обмена через указатели
void safety_change( int* const a, int* const b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//реализация функции с указателем в качестве входной переменной
void summa(short int a, short int b, int* summa){
	*summa =  a + b;
}

int main(void){
	// для корректной работы printf и scanf
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	// использование функции
	int a = 9;
	int b = 3;
	printf("Было          a равно %d b равно %d \n", a,b);
	wrong_change(a,b);
	printf("Wrong change: a равно %d b равно %d \n", a,b);
	change(&a, &b);
	printf("Change        a равно %d b равно %d \n", a,b);
	int c;
	summa(1,2,&c);
	printf("c равно %d  \n", c);
	return 0;
}

