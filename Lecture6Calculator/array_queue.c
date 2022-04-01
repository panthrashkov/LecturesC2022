/*
 * array_queue.c
 *
 *  Created on: 1 апр. 2022 г.
 *      Author: Alex
 */
#include "queue.h"

static char queue[QUEUE_MAX_SIZE][QUEUE_TYPE_SIZE];
static int  ifront[QUEUE_TYPE_SIZE] = {0, 0};
static int icount[QUEUE_TYPE_SIZE] = {0, 0};

void enqueue(char element, queue_type type){
	if(icount[type] < QUEUE_MAX_SIZE){
		queue[ifront[type] + icount[type]][type] = element;
		icount[type]++;
	}
}

char dequeue(queue_type type){
  if(icount[type] > 0){
	  icount[type]--;
	  return queue[ifront[type]++][type];
  } else {
	  return 0;
  }
}
