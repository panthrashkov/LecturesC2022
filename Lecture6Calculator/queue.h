/*
 * queue.h
 *
 *  Created on: 1 апр. 2022 г.
 *      Author: Alex
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUE_MAX_SIZE 100

typedef enum{
	INPUT,
	OUTPUT,
	QUEUE_TYPE_SIZE
}queue_type;


void enqueue(char, queue_type);
char dequeue(queue_type);


#endif /* QUEUE_H_ */
