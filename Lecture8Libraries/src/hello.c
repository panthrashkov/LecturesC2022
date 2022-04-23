/*
 ============================================================================
 Name        : Lecture8Libraries.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// компиляция и компоновка
//gcc -Wall -c src/hello.c  -o hello.o
//nm hello.o
//gcc -Wall hello.o -o hello
//nm hello.exe
// создание библиотеки
//gcc -g -Wall -c src/sum.c -o sum.o
//ar -rcs libsum.a sum.o
// https://stackoverflow.com/questions/57648076/what-does-it-mean-to-add-an-index-to-an-archive-file
//https://habr.com/ru/post/473740/


#include <stdio.h>
#include <stdlib.h>

char msg1[] = "Hello, world.";
const char msg[] = "Hello, world.";

int main(void) {
	gets(msg1);
	puts(msg1); /* prints !!!Hello World!!! */

	return EXIT_SUCCESS;
}
