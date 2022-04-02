/*
 * linked_list.h
 *
 *  Created on: 31 мар. 2022 г.
 *      Author: Alex
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>

#define MAX_LIST_SIZE = 30

typedef struct node {
	int data;
	struct node * next;
}node;

// утилитные функции
node* create_node(int data);
node* add_node(node * head, int payload);
void remove_node(node * head);
void apply (node * phead, void (*fp) (void *, void *), void * arg);

// более "объектный" подход
void init(int data);
node* get_root(void);
inline int get_list_size();
void add_node_to_front(int payload);
void add_node_to_back( int payload);




#endif /* LINKED_LIST_H_ */
