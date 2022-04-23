/*
 * testfp.c
 *
 *  Created on: 9 ���. 2022 �.
 *      Author: Alex
 */

typedef int (*funp)(int);

int doubleValue(int v){
	return 2*v;
}


int main(void){
	// ��������� �� �������
	void * p = doubleValue;
	printf("double %d \n", ((funp) p)(5));

// ������������ ��������� (����������� ���������)
	int value = 100; //������� ���������� ��� ������ ������
	int * const const_pointer = &value; //������������ ���������� ������������� ���������� � ���� �����
	printf("const_pointer %d %p\n", *const_pointer, const_pointer);

// ������ �������� �������� ���������, �� ����� �������� �������� �� ������� �� ���������
//	int value2 = 101;
//	const_pointer = &value;
	*const_pointer = 101;
	printf("const_pointer %d %p\n", *const_pointer, const_pointer);

	//  ��������� �� ������������ ��������(��������� �� ���������)
	const int * pointer_to_const = &value;
	printf("pointer_to_const %d %p\n", *pointer_to_const, pointer_to_const);
	// ������ �������� �������� �� ���������, �� ����� �������� ��� �����
//	*pointer_to_const = 102;
	int value2 = 101;
	pointer_to_const = &value2;
	printf("pointer_to_const %d %p\n", *pointer_to_const, pointer_to_const);

	// ������ �������� �� ��������� �� �������� �� ���������
	const int * const const_pointer_to_const = &value;
//	const_pointer_to_const = &value2;
//	*const_pointer_to_const = 101;

//	const int * const* *const* * * x;
}
