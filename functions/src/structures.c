/*
 * structures.c
 *
 *  Created on: 08.04.2014
 *      Author: setup
 */
// Объявление структуры
typedef struct{
	int x;
	int y;
}Point;

//реализация функции c копированием структуры
void printCoordinate(Point A){
	A.x  = 10;
	printf("1 Координата x точки равна %d, координата y равна %d \n",A.x,A.y);
}

//реализация функции с копированием указателя на структуру
void printCoordinateFast(const Point* const  A){
	printf("2 Координата x точки равна %d, координата y равна %d \n",A->x,A->y);
}

int main(void){
	Point B = {.x = 10,.y = -1};
	printCoordinate(B);
	printCoordinateFast(&B);
}
