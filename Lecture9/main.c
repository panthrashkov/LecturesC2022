/*
 * main.c
 *
 *  Created on: 21 апр. 2022 г.
 *      Author: Alex
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdarg.h>

FILE *test;

void atmainexit1(void) {
	printf("atmainexit1 %d \n ", clock());
}

void atmainexit2(void) {
	printf("atmainexit2 %d \n", clock() / CLOCKS_PER_SEC);
	// fflush(test);
}

int sum(int num, ...) {
	va_list ap;
	va_start(ap, num);
	int total = 0;
	while (num > 0) {
		total +=va_arg(ap , int);
		num--;
	}
	va_end(ap);
	return total;
}

int main(void) {
	// перенаправление потока ввода вывода.
//	test = freopen( "stdout.txt", "w", stdout );

// функция при завершении программы
	atexit(atmainexit1);
	atexit(atmainexit2);
	system("ls");

	assert(3 == 3);

	printf("sum 3 %d \n", sum(3, 1 ,2, 3));
	printf("sum 4 %d \n", sum(4, 10 ,20, 1, 4));

	exit(EXIT_SUCCESS);
}
