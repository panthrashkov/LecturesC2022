/*
 * main.c
 *
 *  Created on: 9 ���. 2022 �.
 *      Author: Alex
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int global_gcd = 0;

void swap(int *, int * );
void gcd_use_global(int some_value, int );
void gcd_use_pointer(int , int , int* );

char * get_message(){
	char  msg[] = "message";
	printf("local %s", msg);
	return msg;
}

int gcd(int a, int b){
	printf("address a = %p, b = %p \n", &a, &b);
	while(b){
		printf("gcd(%d, %d) \n", a, b);
		int temp = b;
		b = a%b;
		a = temp;
	}
	printf("gcd(%d, %d) \n", a, b);
	return a;
}


int main(void) {
	// ���������
//	int value = 0x1;
//	int * pointer, *pointer1 = &value;
//	printf("address pointer %p \n", pointer);
//	printf("value int = %d \n", *pointer);

	// ������������� �� ������������������� ���������
//	int *null_pointer = NULL;
//	printf("value null_pointer = %d \n", *null_pointer);
    // ���������� ����
//	double *dp = (double *) pointer;
//	double dvalue = *dp;
//	printf("address double pointer %p \n", dp);
//	printf("value double = %lf \n", dvalue);
    // �������
//	int arr[3] = {2, 1, 0};
//	printf("first array element %d \n", arr[1]);
//	printf("array name is pointer %p = %p \n", arr, &arr[0]);
//	printf("array name is pointer %p + 1 = %p \n", &arr[0], &arr[0]+1);
	// ������ - ������ �������������
	//arr = &value;
	// ������� ����������� �����
//	char hello[20];
//	char * phello = strcpy(hello, "Hello ");
//	const char * world = "world!";
//	char * helloWorld = strcat(phello, world);
//	printf("strcat source address %p result address %p result %s \n",
//			phello, helloWorld, helloWorld);
	// ���� �������
//	int x = 30;
//	int y = 45;
//	printf("address x = %p, y = %p \n", &x, &y);
	// �������� �������� ����������
//	printf("gcd(%d, %d) = %d \n", x, y, gcd(x, y));
	// �������� ������� ����������
//	swap(&x, &y);
//	printf("x = %d, y = %d \n", x, y);
	// ������������� ���������� ���������� ��� ��������/������
	// �������� �������
//	gcd_use_global(x, y);
//	printf("gcd_use_global(%d, %d) = %d \n", x, y, global_gcd);
	// ������������� ���������� ��� ����������� �������� �� �������
//	int result;
//	gcd_use_pointer(x, y, &result);
//	printf("gcd_use_pointer(%d, %d) = %d \n", x, y, result);

	// ����������� ��������� �� �������
	puts(get_message());


	return 1;
}

void gcd_use_global(int a, int b){
	global_gcd = gcd(a, b);
}

void gcd_use_pointer(int a, int b, int * result){
	*result = gcd(a, b);
}


void swap(int *px, int *py ){
	printf("address px = %p, py = %p \n", px, py);
	int temp = *px;
	*px = *py;
	*py = temp;
}


