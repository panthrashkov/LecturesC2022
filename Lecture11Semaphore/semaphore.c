#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define SLOTS 5
#define ITEMS 10

sem_t mutex, slots, items;


void * produce(void * arg){
	int i;
	for (i = 0; i < ITEMS; i++){
		sem_wait(&slots);
		sem_wait(&mutex);
		printf("produced (%d)", pthread_self());
		printf(":%d \n", i+1);
		sem_post(&mutex);
		sem_post(&items);
	}
	return NULL;
}



void* consume(void * arg){
	int i;
	for (i = 0; i < ITEMS; i++){
		sem_wait(&items);
		sem_wait(&mutex);
		printf("consumed (%d)", pthread_self());
		printf(":%d \n", i+1);
		sem_post(&mutex);
		sem_post(&slots);
	}
	return NULL;
}

int main(int args, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);

	pthread_t cons_thread, prod_thread ;

	sem_init(&mutex, 0, 1);
	sem_init(&slots, 0, SLOTS);
	sem_init(&items, 0, 0);

	pthread_create (&prod_thread ,NULL, produce ,NULL );
	pthread_create (&cons_thread ,NULL, consume ,NULL );
	pthread_join (cons_thread ,NULL) ;
	pthread_join (prod_thread ,NULL) ;

	sem_destroy(&mutex);
	sem_destroy(&slots);
	sem_destroy(&items);

	return 0;
}

