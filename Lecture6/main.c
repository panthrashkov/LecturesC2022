/*
 * main.c
 *
 *  Created on: 20 мар. 2022 г.
 *      Author: Alex
 */

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 6

void swap(int **a, int **b) {
	int *temp = *a;
	*a = *b;
	*b = temp;
}

int arr[ARRAY_SIZE] = { 6, 3, 2, 4, 1, 5 };
int *sorted_array[ARRAY_SIZE] = { &arr[0], &arr[1], &arr[2], &arr[3], &arr[4],
		&arr[5] };

void shift_element(unsigned int i) {
	int *pvalue;
	for (pvalue = sorted_array[i]; i && *sorted_array[i - 1] > *pvalue; i--) {
		sorted_array[i] = sorted_array[i-1];
	}
	sorted_array[i] = pvalue;
}

void insertion_sort(unsigned int array_length){
	unsigned int i;
	for(i = 1; i < array_length; i++){
		if(*sorted_array[i] < *sorted_array[i - 1]){
			shift_element(i);
		}
	}
}

void printPointerArray(char *message, int **array, unsigned int arrayLength) {
	printf("%s ", message);
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", *array[i]);
	}
	printf("\n");
}

void printArray(char *message, int *array, unsigned int arrayLength) {
	printf("%s ", message);
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

int main(void) {
	int n = 4;
	int *pn = &n;
	int **ppn = &pn;

	int k = 2;
	int *pk = &k;
	int **ppk = &pk;

	swap(ppn, ppk);
	printf("n = %d, k = %d, pn = %d, pk= %d \n", n, k, *pn, *pk);

	char * str1 = "1";
	char * arrayCharP[2] = {str1, "2"};

	printf("n0 = %p, n1 = %p,  str1 = %p \n", &arrayCharP[0], &arrayCharP[1], str1);

	printArray("before sort array \n", arr, ARRAY_SIZE);
	printPointerArray("before sort pointer array \n", sorted_array, ARRAY_SIZE);
	insertion_sort(ARRAY_SIZE);
	printArray("after sort array \n", arr, ARRAY_SIZE);
	printPointerArray("after sort pointer array \n", sorted_array, ARRAY_SIZE);

}
