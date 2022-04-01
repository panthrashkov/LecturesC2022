/*
 * array_queue.c
 *
 *  Created on: 1 апр. 2022 г.
 *      Author: Alex
 */
#include "queue.h"

static float queue[QUEUE_MAX_SIZE];
static int  ifront = 0;
static int icount = 0;



void enqueue(float element){
	if(icount < QUEUE_MAX_SIZE){
		queue[(ifront + icount) % QUEUE_MAX_SIZE] = element;
		icount++;
	}
}

//float dequeue(void){
//  if(icount > 0){
//	  icount--;
//	  return queue[ifront++];
//  } else {
//	  return 0.;
//  }
//}

float dequeue(void){
  if(icount > 0){
	  icount--;
	  float element = queue[ifront++];
	  if(ifront == QUEUE_MAX_SIZE){
		  ifront = 0;
	  }
	  return element;
  } else {
	  return 0.;
  }
}
