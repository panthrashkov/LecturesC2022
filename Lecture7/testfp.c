/*
 * testfp.c
 *
 *  Created on: 9 апр. 2022 г.
 *      Author: Alex
 */

typedef int (*funp)(int);

int doubleValue(int v){
	return 2*v;
}


int main(void){
	// Указатели на функции
	void * p = doubleValue;
	printf("double %d \n", ((funp) p)(5));

// неизменяемый указатель (константный указатель)
	int value = 100; //обычная переменная для взятия адреса
	int * const const_pointer = &value; //Указательная переменная зафиксировала сохранённый в себя адрес
	printf("const_pointer %d %p\n", *const_pointer, const_pointer);

// нельзя изменить значение указателя, но можно изменить значение на которое он указывает
//	int value2 = 101;
//	const_pointer = &value;
	*const_pointer = 101;
	printf("const_pointer %d %p\n", *const_pointer, const_pointer);

	//  указатель на неизменяемое значение(указатель на константу)
	const int * pointer_to_const = &value;
	printf("pointer_to_const %d %p\n", *pointer_to_const, pointer_to_const);
	// нельзя изменить значение по указателю, но можно изменить сам адрес
//	*pointer_to_const = 102;
	int value2 = 101;
	pointer_to_const = &value2;
	printf("pointer_to_const %d %p\n", *pointer_to_const, pointer_to_const);

	// нельзя изменить ни указатель ни значение по указателю
	const int * const const_pointer_to_const = &value;
//	const_pointer_to_const = &value2;
//	*const_pointer_to_const = 101;

//	const int * const* *const* * * x;
}
