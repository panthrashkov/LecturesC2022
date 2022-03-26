/*
 * main.c
 *
 *  Created on: 13.12.2012
 *      Author: Admin
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include <math.h>
#include <errno.h>

#include <stdlib.h>

int main(void){
	// STDIO.H
	// отмена буферизации потоков данных
//	int setvbuf(FILE *stream, char *buf, int mode, size_t size);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
// Открытие файла
//	FILE *fopen(const char *filename, const char *mode);
//	FILE* file = fopen("test","r");
// 	Чтение закрытие см в лабораторной по модулям.
//	fclose(file);

	// CTYPE.H
	// int isdigit(int c);
	int x = '5', y = 'f';
	printf("x число? %d, y число?  %d \n",isdigit(x),isdigit(y));
	if(isdigit(x)){
		printf("Условие - истина \n");
	}

	//<STRING.H>
	//char * strcat (char*, const char*);
	char str1[13] = "13 pm1 ";
	char str2[7] = "rules!";
	char* s = strcat(str1,str2);
	printf("%s \n", s);
	printf("%s \n", str1);

	// <MATH.H>
	// double __cdecl pow (double, double);
	double z = pow(2,4);
	printf("2 в 4 степени равно %f \n", z);
	printf("ошибка до вызова %d \n", errno);
	acos(3);
	printf("ошибка после вызова %d \n", errno);

	// <STDLIB.H>
	// int rand	(void);
	x = rand();
	printf("Cлучайное число %d \n", x);

	// выделение памяти
	int* p = calloc(1,sizeof(int));
	*p = 10;
	printf("выделено первый раз адрес %p значение %d \n", p,*(p));
	free(p);

	int* p1 = calloc(1,sizeof(int));
	printf("выделено второй раз адрес %p значение %d \n", p1,*(p1));
	free(p1);




	return 0;
}
