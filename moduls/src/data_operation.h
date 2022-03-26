/*
 * data_operation.h
 *
 *  Created on: 11.12.2012
 *      Author: Admin
 */

#ifndef DATA_OPERATION_H_
#define DATA_OPERATION_H_
enum{
	Ok,
	Error_File_Open,
	Error_No_Enough_Data,

};

int read_data_from_file(char* fileName, int * buffer, int size);
int write_data_to_file(char* fileName, int * buffer, int size);



#endif /* DATA_OPERATION_H_ */
