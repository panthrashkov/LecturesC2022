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

typedef  int Int32;
typedef signed short int Uint16;

int main(void) {
	// Неявное преобразование типов
	// С
	printf("Multiple %d \n size of %d \n", UCHAR_MAX * UCHAR_MAX, sizeof(UCHAR_MAX * UCHAR_MAX));
	printf("Multiple %d \n size of %d \n", SHRT_MAX * SHRT_MAX, sizeof(SHRT_MAX * SHRT_MAX));
	long long test = (long long) INT_MAX * (long long) INT_MAX;
	printf("Multiple %f \n size of %d \n", (long long) INT_MAX * (long long) INT_MAX, sizeof(INT_MAX * INT_MAX));
	// Groovy
//	def x = 255
//	​println(x*x)
//
//	def y = 32767
//	println(y*y)
//
//	def z = 2147483647
//	println(z*z)

	// kotlin
//	fun main() {
//	   val x = 255
//	println(x*x)
//
//	val y = 32767
//	println(y*y)
//
//	val z = 2147483647
//	println(z.toLong()*z)
//	}

	// python
//	x = 255
//	print(x*x)
//	print(type(x*x))
//
//	y = 32767
//	print(y*y)
//	print(type(y*y))
//
//	z = 2147483647
//	print(z*z)
//	print(type(z*z))


}
