/*
 * structures.c
 *
 *  Created on: 08.04.2014
 *      Author: setup
 */
// ���������� ���������
typedef struct{
	int x;
	int y;
}Point;

//���������� ������� c ������������ ���������
void printCoordinate(Point A){
	A.x  = 10;
	printf("1 ���������� x ����� ����� %d, ���������� y ����� %d \n",A.x,A.y);
}

//���������� ������� � ������������ ��������� �� ���������
void printCoordinateFast(const Point* const  A){
	printf("2 ���������� x ����� ����� %d, ���������� y ����� %d \n",A->x,A->y);
}

int main(void){
	Point B = {.x = 10,.y = -1};
	printCoordinate(B);
	printCoordinateFast(&B);
}
