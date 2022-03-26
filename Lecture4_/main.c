/*
 * main.c
 *
 *  Created on: 9 мар. 2022 г.
 *      Author: Alex
 */
#include <stdio.h>

int main(void) {
	int value = 2;
	int *pointer = &value;
	printf("address %p \n", pointer);
	printf("value = %d", *pointer);
}
