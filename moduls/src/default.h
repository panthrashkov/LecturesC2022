/* ���� ������������
 *  Created on: 28.02.201   Author: Pankov
 */
// ���� ���������
#include "data_operation.h"

// �������� �������� ����������
#ifndef DEFAULT_H_
#define DEFAULT_H_
// ���� ��������
#define PI 3.14
enum{
	Constanta = 10,
};
// ���� ����������� ����� ������
typedef int Parameter;
typedef struct {
	char name[40];
	unsigned int gruppa;
}Student;
// ���������� �������
int calc_mean(int* buffer, int size);
void init_module(void);
#endif /* DEFAULT_H_ */
