/*
 * data_operation.c
 *
 *  Created on: 11.12.2012
 *      Author: Admin
 */
#include "stdio.h"
#include "data_operation.h"

int read_write_counter  = 0;
static int static_read_write_counter  = 0;
int read_data_from_file(char* fileName, int * buffer, int size){
	// ���������� ���������� �����
	read_write_counter++;
	static_read_write_counter++;
	// ���������� ���������� �������
	static int global_in_function = 0;
	// ������ �������
	FILE* file = fopen(fileName,"r");
	if(file == NULL){
		return Error_File_Open;
	}
	int i;
	for(i = 0; i < size; i++){
		buffer[i] = fgetc(file);
		if(buffer[i] == EOF){
			return Error_No_Enough_Data;
		}
	}
	fclose(file);
	global_in_function++;
//	printf("������ = %d \n",global_in_function++);
	return Ok;
}

int write_data_to_file(char* fileName, int * buffer, int size){
	// ���������� ���������� �����
	read_write_counter++;
	static_read_write_counter++;
	// ���������� ���������� �������
	static int global_in_function = 0;
	// ������ �������
	FILE* file = fopen(fileName,"w");
	if(file == NULL){
		return Error_File_Open;
	}
	int i;
	for(i = 0; i < size; i++){
		fputc(buffer[i], file);

	}
	fclose(file);
	return Ok;
}
inline int get_static_counter(){return static_read_write_counter;};


