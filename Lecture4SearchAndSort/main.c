/*
 * main.c
 *
 *  Created on: 10 мар. 2022 г.
 *      Author: Alex
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 6
#define ARRAY_LENGTH(arr) \
 (sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof((arr)[0]))

int arr[ARRAY_SIZE] = { 6, 3, 2, 4, 1, 5 };

int* linear_search(int val) {
	int *parr, *parrend = arr + ARRAY_LENGTH(arr);
	for (parr = arr; parr < parrend; parr++) {
		if (*parr == val)
			return parr;
	}
	return NULL;
}

void printArray(char *message, int *array, unsigned int arrayLength);
void insertion_sort(int *array, unsigned int arrayLength);
void swap(int* i, int* j);
void quick_sort(int * arr, unsigned int left, unsigned int right, unsigned int arrayLength);

int main(void) {
	// линейный поиск
//	int *pointer = linear_search(4);
//	int index = pointer - arr;
//	printf("first element address %p, value address= %p, index = %d \n", arr, pointer, index);
	// сортировка вставками
//	printArray("before sort \n", arr, ARRAY_SIZE);
//	insertion_sort(arr, ARRAY_SIZE);
//	printArray("after sort \n", arr, ARRAY_SIZE);
	// быстрая сортировка
	printArray("before sort \n", arr, ARRAY_SIZE);
	quick_sort(arr, 0, ARRAY_SIZE-1, ARRAY_SIZE);
	printArray("after sort \n", arr, ARRAY_SIZE);
	return 1;
}

void printArray(char *message, int *array, unsigned int arrayLength) {
	printf("%s ", message);
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

void shift_element(unsigned int i, int *array, unsigned int arrayLength) {
	// вытаскиваем элемент из массива
	int current_value = array[i];
	// сдвигаем остальные элементы вправо
	// доходим либо до начала массива i != 0, либо до первого элемента меньше current_value
	for (; i != 0 && array[i - 1] > current_value; i--) {
		array[i] = array[i - 1];
		printArray("shift  ", array, arrayLength);
	}
	// вставляем на место
	array[i] = current_value;
	printArray("shift end  ", array, arrayLength);
}

void insertion_sort(int *array, unsigned int arrayLength) {
	unsigned int i;
	for (i = 1; i < arrayLength; i++) {
		if (array[i] < array[i - 1]) {
			shift_element(i, array, arrayLength);
		}
	}
}

int index_uncorrect(unsigned int left, unsigned int right) {
	return left >= right;
}

void quick_sort(int * arr, unsigned int left, unsigned int right, unsigned int arrayLength) {
	unsigned int i, movedToLeft;
	int pivot;
	// проверка, что индексы заданы корректно
	if (index_uncorrect(left, right)) {
		printf("0. It's all guys \n");
		return;
	}
	// индекс середины сортируемой части массива
	unsigned int middleIndex = (left + right) / 2;
	// опорный равен среднему элементу в массиве
	pivot = arr[middleIndex];
	// переносим опорный элемент в начало сортируемой части
	swap( arr + left, arr + middleIndex);
	movedToLeft = left;
	printf("1. pivot %d, left %d, right %d\n", pivot, left, right);
	printArray("2. recursion  ", arr + left, arrayLength);
	// итерация по части массива начиная со второго элемента (первым стоит опорный)
	for (i = left + 1; i <= right; i++) {
		int* pointer_to_current_element = arr + i;
		if (*pointer_to_current_element < pivot) {
			movedToLeft++;
			printf("3. find smaller on i %d movedToLeft %d \n", i-left, movedToLeft-left);
			swap(arr + movedToLeft, pointer_to_current_element);
		}
	}
	printArray("4. recursion", arr + left, arrayLength);
	swap(arr + left, arr  + movedToLeft); /* restore partition elem */
	printf("5. pivot %d, left %d, right %d\n", pivot, left, right);
	if(movedToLeft > left){
		printArray("6. recursion movedToLeft > left", arr + left, arrayLength);
		quick_sort(arr, left, movedToLeft-1, movedToLeft-left);
	}
	if(movedToLeft < right){
		printArray("6. recursion movedToLeft < right", arr + left, arrayLength);
		quick_sort(arr, movedToLeft + 1 , right, right - movedToLeft);
	}
}


void swap(int* i, int* j) {
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

