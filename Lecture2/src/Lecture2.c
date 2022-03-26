/*
 ============================================================================
 Name        : Lecture2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

#define EXP 271L
#define String "Строка"

typedef int Int32;
typedef unsigned short int Uint32;

int main(void) {
	// Изучение размеров типов данных
	int size_char = sizeof(unsigned char);
	int size_short_int = sizeof(short int);
	int size_int = sizeof(int);
	int size_long = sizeof(long);
	int size_long_long_int = sizeof(long long int);
	int size_float = sizeof(float);
	Int32 size_double = sizeof(double);

	printf("Size of char = %d byte \n", size_char);
	printf("Size of short int = %d byte \n", size_short_int);
	printf("Size of  long int = %d byte \n", size_long);
	printf("Size of long long int = %d byte \n", size_long_long_int);
	printf("Size of int = %d byte \n", size_int);
	printf("Size of float = %d byte \n", size_float);
	printf("Size of double = %d byte \n", size_double);
	printf("-----------------------\n");
	printf("-----------------------\n");

	int n = 1;
	// little endian if true
	if (*(char*) &n == 1) {
		printf("little endian\n");
	} else {
		printf("big endian\n");
	}

	char x14 = 10 + 255; //;70
	printf("variable char equals %d \n", x14);
	char ch = 'F';
	printf("variable char 'F' equals %d \n", 'F');
	printf("variable char 70 equals %c \n", 70);
	char binary = 0b00000101;
	printf("variable char equals %d \n", binary & 0b00000100);
	int x = 017;

	int y = 12;

	printf("x > y %d \n", x > y);
	short int s = 0xFF12;
	char c = -1;
	unsigned char uc = -1;
	printf("variable char equals %d \n", uc);
//	puts("hel" + "lo");
	puts("hel" "lo \n");
	enum sz {
		S = 0, L = -3, XL
	};
	printf("%d XL \n", XL);

	double float_x = 1000000000001F;
	printf("is x + 0.00000000000000000000000000001 greater x - %d\n", (x + 0.00000000000000000001) > x );


	// модификаторы доступа
	register short int register_x = 2;
	volatile long int volatile_x;
	static int static_x;



}
