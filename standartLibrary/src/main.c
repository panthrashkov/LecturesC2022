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
	// ������ ����������� ������� ������
//	int setvbuf(FILE *stream, char *buf, int mode, size_t size);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
// �������� �����
//	FILE *fopen(const char *filename, const char *mode);
//	FILE* file = fopen("test","r");
// 	������ �������� �� � ������������ �� �������.
//	fclose(file);

	// CTYPE.H
	// int isdigit(int c);
	int x = '5', y = 'f';
	printf("x �����? %d, y �����?  %d \n",isdigit(x),isdigit(y));
	if(isdigit(x)){
		printf("������� - ������ \n");
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
	printf("2 � 4 ������� ����� %f \n", z);
	printf("������ �� ������ %d \n", errno);
	acos(3);
	printf("������ ����� ������ %d \n", errno);

	// <STDLIB.H>
	// int rand	(void);
	x = rand();
	printf("C�������� ����� %d \n", x);

	// ��������� ������
	int* p = calloc(1,sizeof(int));
	*p = 10;
	printf("�������� ������ ��� ����� %p �������� %d \n", p,*(p));
	free(p);

	int* p1 = calloc(1,sizeof(int));
	printf("�������� ������ ��� ����� %p �������� %d \n", p1,*(p1));
	free(p1);




	return 0;
}
