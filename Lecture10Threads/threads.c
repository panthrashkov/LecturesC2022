/*
 * main.c
 *
 *  Created on: 28 апр. 2022 г.
 *      Author: Alex
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define NELEMENTS 5000
#define BLK_SIZE 1000
#define NTHREADS (NELEMENTS/ BLK_SIZE )

int volatile global = 0;

void printGlobal() {
	while (global) {
		printf("Main program complete \n");
		sleep(1);
	}
}

void set_global() {
	global = 1;
}

void* printHello(void *threadid) {
	set_global();
	long tid = (long) threadid;
	printf("Hello World ! I t's me, thread #%ld ! \n", tid);
	pthread_exit(NULL);
}

int main(int args, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	pthread_t threads[NUM_THREADS];
	int rc;
	for (long t = 0; t < NUM_THREADS; t++) {
		printf("In main: creating thread %ld \n", t);
		rc = pthread_create(&threads[t], NULL, printHello, (void*) t);
		if (rc) {
			printf("ERROR; return code from pthread_create () is %d \n", rc);
			exit(-1);
		}
	}

	sleep(1);
	printGlobal();

	pthread_exit(NULL);
}

