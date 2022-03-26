/*
 * main.c
 *
 *  Created on: 07.12.2012
 *      Author: admin
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// ������������ ���������� ������� ������ �������� ����������
void wrong_change(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}
//���������� ������� ������ ����� ���������
void change(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// ����� ������ (����������) ���������� ������� ������ ����� ���������
void safety_change( int* const a, int* const b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//���������� ������� � ���������� � �������� ������� ����������
void summa(short int a, short int b, int* summa){
	*summa =  a + b;
}

int main(void){
	// ��� ���������� ������ printf � scanf
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	// ������������� �������
	int a = 9;
	int b = 3;
	printf("����          a ����� %d b ����� %d \n", a,b);
	wrong_change(a,b);
	printf("Wrong change: a ����� %d b ����� %d \n", a,b);
	change(&a, &b);
	printf("Change        a ����� %d b ����� %d \n", a,b);
	int c;
	summa(1,2,&c);
	printf("c ����� %d  \n", c);
	return 0;
}

