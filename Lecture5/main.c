#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#pragma pack(1)

struct point {
	int x;
	int y;
};

struct employee {
	char name[100];
	char surname[100];
	unsigned int age;
};

struct triangle {
	struct point ptA;
	struct point ptB;
	struct point ptC;
};

// __attribute__((packed))
struct packed {
	int c;
	long long i;
} __attribute__((packed));

//__attribute__((aligned(1)))
//
struct aligned {
	int c; // 4 байта
	// 4 байта
	long long i; // 8 байт
};

typedef struct {
	struct point ptA;
	struct point ptB;
} line;

typedef union union_data {
	int intData;
	float floatData;
	char *pChar;
} union_data;

struct flag {
	unsigned int is_color :1;
	unsigned int has_sound :1;
	unsigned int limit_speed :2;
};

void printLine(line *ab) {
	printf("line ab ptA %d, %d \n", ab->ptA.x, ab->ptA.y);
	(*ab).ptA.x = 3;
}

int main(void) {
	struct point a = { .x = 0, .y = 0 };
	a.x = 0;
	struct triangle abc = { { 0, 0 }, { 10, 10 }, { 10, 0 } };
	printf("triangle ptA %d, %d \n", abc.ptA.x, abc.ptA.y);

	line ab = { .ptA = { .x = -1, .y = 1 }, { 10, 10 } };
	printLine(&ab);
	printLine(&ab);

	printf("size of aligned %d \n", sizeof(struct aligned));
//	printf("size of packed %d \n", sizeof(struct packed));

	union_data d1, d2, d3;
	d1.floatData = 3.14;
	printf("d1 int = %d, d1 float = %f \n", d1.intData, d1.floatData);

	struct flag f;
	f.has_sound = 1;
	f.limit_speed = 0b11;
	printf("has_sound = %d, limit_speed = %d \n", f.has_sound, f.limit_speed);

	FILE *file = fopen("C://Temp/test.txt", "r");
	if (file != NULL) {
		int input_character = fgetc(file);
		while (input_character != EOF) {
			printf("%c", input_character);
			input_character = fgetc(file);
		}
	}
	fclose(file);
}




