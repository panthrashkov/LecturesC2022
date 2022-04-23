/*
 * main.c
 *
 *  Created on: 14 апр. 2022 г.
 *      Author: Alex
 */

// компоновка из объектников
// gcc -Wall -c src/main.c -o src/main.o
// gcc -Wall src/sum.o src/main.o  -o sum
// компоновка из библиотек
// gcc -g -Wall -L./lib src/main.o  -lsum -o sum

#include "sum.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

//int puts (const char * t){
//	printf("%d", 10);
//	return 1;
//}

int main(void){
	printf("%d", sum(1, 2));
	//puts(NULL);
	return 1;
}
