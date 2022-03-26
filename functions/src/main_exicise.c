/*
 * main.c
 *
 *  Created on: 05.12.2012
 *      Author: admin
 */

// ���������� ������������ ������
#include <stdio.h>
#include <math.h>
//���������� ������������ ��������
enum {
	TAU,
	Informatika,
	NumberExamsSubject,
};
enum {
	NumberStudents = 3,
};
// ���������� ����������� �����
typedef struct{
	char  name[40];
	unsigned char examsMark[NumberExamsSubject];
	float meanExamsMark;
}recordBook;

// ���������� �������
void for_correct_work_printf(void);
void init_from_keyboard(recordBook* students);
void calc_mean_mark(recordBook* students);
float calc_mean_group(recordBook* students);
void calc_mean_student(recordBook* students, float mean_value, int* mean_index);

int main(void){
	// ��� ���������� ������ printf � scanf
	for_correct_work_printf();
	// ������������� � ������ ���������
	recordBook students[] = {
			{"������", {4,4}},
			{"������", {5,5}},
			{"�������", {3,4}}
	};
	// ������������� � ������� ����������
	init_from_keyboard(&students[0]);
	// ���������� ������� ������ �� ���������
	calc_mean_mark(&students[0]);
	// ���������� ������� ������ �� ������
	float meanMarkGroup = calc_mean_group(&students[0]);
	// ���������� �������� � ������� ����� ������� � �������
	int mean_student_index=0;
	calc_mean_student(&students[0], meanMarkGroup, &mean_student_index);
	// ����� ���������� �� �����
	printf(" ����� ������� ������� - %s",students[mean_student_index].name);
	return mean_student_index;
}

void for_correct_work_printf(void){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

void init_from_keyboard(recordBook* students){
	int i = 0;
	int j = 0;
	for(i = 0; i < NumberStudents;  i++){
		printf("������� ������� %d  �������� \n", i+1 );
		scanf("%s", (students+i)->name);
		for(j = 0; j < NumberExamsSubject;j++ ){
			printf("������� ������ %d  ��������  ��  %d �������\n", i+1, j+1 );
			scanf("%d", (int*)&((students+i)->examsMark[j]));
		}
	}
}

float calc_mean_group(recordBook* students){
	int i = 0;
	float meanMarkGroup = 0;
	for(i = 0; i < NumberStudents;  i++){
		meanMarkGroup += (students+i)->meanExamsMark;
	}
	meanMarkGroup = meanMarkGroup/NumberStudents;
	return meanMarkGroup;
}


void calc_mean_mark(recordBook* students){
	int i = 0;
	int j = 0;
	for(i = 0; i < NumberStudents;  i++){
		int summa = 0;
		for(j = 0; j < NumberExamsSubject;j++ ){
			 summa += (students+i)->examsMark[j];
		}
		(students+i)->meanExamsMark = (float)summa/NumberExamsSubject;
	}
}

void calc_mean_student(recordBook* students, float mean_value, int* mean_index){
	float difference = 0;
	float min_difference = fabs(mean_value - students->meanExamsMark);// ��������� �������
	*mean_index = 0;
	int i;
	for(i = 1; i < NumberStudents;  i++){
		difference =  fabs(mean_value - (students+i)->meanExamsMark);
		if(difference < min_difference){
			min_difference = difference;
			*mean_index = i;
		}
	}
}


