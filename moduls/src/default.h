/* Ѕлок комментариев
 *  Created on: 28.02.201   Author: Pankov
 */
// блок включений
#include "data_operation.h"

// диретивы условной компил€ции
#ifndef DEFAULT_H_
#define DEFAULT_H_
// блок констант
#define PI 3.14
enum{
	Constanta = 10,
};
// блок собственных типов данных
typedef int Parameter;
typedef struct {
	char name[40];
	unsigned int gruppa;
}Student;
// ќбъ€вление функций
int calc_mean(int* buffer, int size);
void init_module(void);
#endif /* DEFAULT_H_ */
