/*
 * r.c
 *
 *  Created on: 07.12.2012
 *      Author: admin
 */

#include <stdio.h>
#include <string.h>
// ���������� �������
void check(char *a, char *b,
           int (*cmp)(const char *, const char *));
int main(void)
{
  char s1[80], s2[80];
  int (*p)(const char *, const char *);
               /* ��������� �� ������� */
  p = strcmp;
  /* ����������� ����� ������� strcmp ��������� p */

  printf("������� ��� ������.\n");
  gets(s1);
  gets(s2);

  check(s1, s2, p); /* �������� ����� ������� strcmp
                       ����������� ��������� p */
  return 0;
}
// ���������� �������
void check(char *a, char *b,
           int (*cmp)(const char *, const char *))
{
  printf("�������� �� ����������.\n");
  int result_compare = (*cmp)(a, b); // �����  ������� �� ���������
  if(!result_compare){
	  printf("�����");
  }else {
	  printf("�� �����");
  }
}
