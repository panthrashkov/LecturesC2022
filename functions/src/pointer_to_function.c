/*
 * r.c
 *
 *  Created on: 07.12.2012
 *      Author: admin
 */

#include <stdio.h>
#include <string.h>
// объявление функции
void check(char *a, char *b,
           int (*cmp)(const char *, const char *));
int main(void)
{
  char s1[80], s2[80];
  int (*p)(const char *, const char *);
               /* указатель на функцию */
  p = strcmp;
  /* присваивает адрес функции strcmp указателю p */

  printf("Введите две строки.\n");
  gets(s1);
  gets(s2);

  check(s1, s2, p); /* Передает адрес функции strcmp
                       посредством указателя p */
  return 0;
}
// реализация функции
void check(char *a, char *b,
           int (*cmp)(const char *, const char *))
{
  printf("Проверка на совпадение.\n");
  int result_compare = (*cmp)(a, b); // вызов  функции по указателю
  if(!result_compare){
	  printf("Равны");
  }else {
	  printf("Не равны");
  }
}
