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

FILE * test;

void atmainexit1(void){
  printf("atmainexit1 %d \n ", clock());
}

void atmainexit2(void){
  printf("atmainexit2 %d \n", clock());

  fflush(test);
}

int main(void){
	// перенаправление потока ввода вывода.
	test = freopen( "stdout.txt", "w", stdout );

	// функция при завершении программы
	atexit(atmainexit1);
	atexit(atmainexit2);


//	assert( 1== 3);
	system("ls");

	exit(EXIT_SUCCESS);
}
