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

void* printHello(void *threadid) {
	long tid = (long) threadid;
	sleep(tid);
	printf("Hello World ! I t's me, thread #%ld ! \n", tid);
	pthread_exit(NULL);
	return threadid;
}

int main(int args, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	void *status;
	/* Initialize and set thread detached attribute */
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (long t = 0; t < NUM_THREADS; t++) {
		printf("In main: creating thread %ld \n", t);
		rc = pthread_create(&threads[t], &attr, printHello, (void*) (t));
		if (rc) {
			printf("ERROR; return code from pthread_create () is %d \n", rc);
			exit(-1);
		}
	}
	/* Free attribute and wait for the other threads */
	pthread_attr_destroy(&attr);
	for (t = 0; t < NUM_THREADS; t++) {
		rc = pthread_join(threads[t], &status);
		if (rc) {
			printf("ERROR; return code from pthread_create () is %d \n", rc);
			exit(-1);
		}
	}

	printf("Main program complete \n");
	pthread_exit(NULL);
}

