/*
 * main.c
 *
 *  Created on: 28.11.2012
 *      Author: admin
 */
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

typedef enum{
	January = 5,//0
	February,//1
	Desember,//2
	NumberMonth,//3
}Month;

typedef enum { RED, GREEN, BLUE } color;

enum{
	RUSSIA,
	USA,
	CHINE,
	FRANCE,
	NUMBER_COUNTRIES,
};
enum{
	GOLD,
	SILVER,
	BRONZE,
	NUMBER_MEDAL_VALUE
};

int medals[NUMBER_COUNTRIES][NUMBER_MEDAL_VALUE];
int medalsRussia[NUMBER_MEDAL_VALUE];

int main(void){
	//	int wage[12];
	Month dfdf = -5;
	int x = 2;
	printf(" число %d \n", x);
	float y = sin(x);
	printf(" синус %f \n", y);
	printf(" число %d \n", x);
	int w[12];
	int wage[] = {0,1,2,3,4,5,6,7,8,9,10,11}; // массив из 12 элементов
	int wageFebruary = wage[1];
	int medals[4][3] = {{1,3,4},
			{5,3,4},
			{1,3,5},
			{1,3,4}};


	int rusMedals = medals[RUSSIA][SILVER];

	gets(&x);

	printf(" число %d \n", x);
/*
	int * massivePointers[NUMBER_COUNTRIES];
	massivePointers[0] = &medals[0][1];


	int x1  =  wage[2];
	int y1  = *(wage + 2);


	char massive[] = {'H','e','y','\0'};//
	char string[] = "Hey";
	printf("%d",strcmp(massive,string));

	int x  = 10; // объ€вл€ем переменную х типа int и инициализируем ее значением 10
	printf(" Ѕыло x = %d \n ",x);
	int* pointerInt = NULL; // объ€вл€ем переменную pointerInt типа указатель на int
	int* pointerInt1;
	int* pointerInt2;
	if(pointerInt == NULL){
		printf("”казатель не инициализирован \n");
	}
	// (или дл€ сокращени€ говор€т: объ€вл€ем указатель на int )
	pointerInt = &x;// присваиваем переменной pointerInt адрес переменной x
	// (или дл€ сокращени€ говор€т: pointerInt указывает на x )
	 *pointerInt = 20;
	printf("—тало x = %d \n",x);
	 */



}
