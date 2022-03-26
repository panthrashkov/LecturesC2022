/*
 * main_task.c
 *
 *  Created on: 02.12.2012
 *      Author: AKILLLL
 */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

enum{
	S1,
	S2,
	NUMBER_STUDENTS,
};
enum{
	INFORMATIKA,
	PHYSICS,
	MATH,
	NUMBER_SUBJECTS
};

int studentIndex = S2;
int subjectIndex = PHYSICS;

int main(void){

	int bals[NUMBER_STUDENTS][NUMBER_SUBJECTS] = {{10,30,40},{50,60,70}};

	int *p;
	p = &bals[studentIndex][subjectIndex];
	*p = 30;

	int summa = bals[studentIndex][INFORMATIKA]
	           + bals[studentIndex][PHYSICS]
	           + bals[studentIndex][MATH];

	float mean  = summa/NUMBER_SUBJECTS;

	printf(" Средний бал = %f \n ", mean);

	int max;
	p = &bals[studentIndex][subjectIndex];




}

