/*
 * main.c
 *
 *  Created on: 28 апр. 2022 г.
 *      Author: Alex
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define USE_MUTEX
#define NUM_THREADS 20

int balance = 500;
pthread_mutex_t mutexbalance = PTHREAD_MUTEX_INITIALIZER ;

void* deposit(void *amount) {
#ifdef USE_MUTEX
	pthread_mutex_lock (&mutexbalance) ;
#endif
	int int_amount = (int) amount;
	printf("deposit %d \n", int_amount);

	int current_balance = balance;
	current_balance += int_amount;
	balance = current_balance;
#ifdef USE_MUTEX
	pthread_mutex_unlock(&mutexbalance) ;
#endif
	return &balance;
}

void* withdraw(void *amount) {
#ifdef USE_MUTEX
	pthread_mutex_lock (&mutexbalance) ;
#endif
	int int_amount = (int) amount;
	printf("withdraw %d \n", int_amount);
	int current_balance = balance;
	sleep(1);
	current_balance -= int_amount;
	balance = current_balance;
#ifdef USE_MUTEX
	pthread_mutex_unlock(&mutexbalance) ;
#endif
	return &balance;
}

int main(int args, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Main program start %d \n", balance);
	pthread_t threads[NUM_THREADS];
	int rc;
	for (long t = 0; t < NUM_THREADS/2; t++) {
		int amount = 100;
		printf("In main: creating deposit %ld \n", amount);
		rc = pthread_create(&threads[t], NULL, deposit, amount);
		if (rc) {
			printf("ERROR; return code from pthread_create () is %d \n",rc);
            exit(-1);
		}
		printf("In main: creating withdraw %ld \n", amount);
		rc = pthread_create(&threads[t+1], NULL, withdraw, amount);
		if (rc) {
			printf("ERROR; return code from pthread_create () is %d \n",rc);
            exit(-1);
		}
	}

#ifndef USE_MUTEX
	sleep(4);
#endif
#ifdef USE_MUTEX
	sleep(NUM_THREADS);
#endif
	printf("Main program complete %d \n", balance);
}

