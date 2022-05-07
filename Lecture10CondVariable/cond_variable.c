#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_cond_t cond_recv=PTHREAD_COND_INITIALIZER ;
pthread_cond_t cond_send=PTHREAD_COND_INITIALIZER ;
pthread_mutex_t cond_mutex=PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t count_mutex=PTHREAD_MUTEX_INITIALIZER ;

int full = 0;
int count = 0;

void * produce(void * arg){
	while(1){
		pthread_mutex_lock(&cond_mutex);
		while(full){
			printf("produced full (%d) \n", full);
			printf("produced (%d) wait \n", pthread_self());
			pthread_cond_wait(&cond_recv, &cond_mutex);
			printf("produced (%d) released \n", pthread_self());
		}
		pthread_mutex_unlock(&cond_mutex);
		pthread_mutex_lock(&count_mutex);
		count++; full = 1;
		printf("produced (%d)", pthread_self());
		printf(":%d \n", count);
		pthread_cond_broadcast(&cond_send);
		pthread_mutex_unlock(&count_mutex);
		if(count >= 10){
			break;
		}
	}
}

void* consume(void * arg){
	while(1){
		pthread_mutex_lock(&cond_mutex);
		while(!full){
			printf("consumed full (%d) \n", full);
			printf("consumed (%d) wait \n", pthread_self());
			pthread_cond_wait(&cond_send, &cond_mutex);
			printf("consumed (%d) released \n", pthread_self());
		}
		pthread_mutex_unlock(&cond_mutex);
		pthread_mutex_lock(&count_mutex);
		full = 0;
		printf("consumed (%d)", pthread_self());
		printf(":%d \n", count);
		pthread_cond_broadcast(&cond_recv);
		pthread_mutex_unlock(&count_mutex);
		if(count >= 10){
			break;
		}
	}
}

int main(int args, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	// Настройки приоритета
	int policy;
	pthread_t cons_thread, prod_thread ;
	pthread_attr_t *attr;
	pthread_attr_init(attr);
	struct sched_param param;
	pthread_attr_getschedparam(attr, &param);
	pthread_attr_setinheritsched(attr, PTHREAD_EXPLICIT_SCHED);
	policy = SCHED_RR;
	pthread_attr_setschedpolicy(attr, policy);
	param.sched_priority = 1;// 1-99
	pthread_attr_setschedparam(attr ,&param);
	// Создание потоков
	pthread_create (&prod_thread, attr, produce ,NULL );
	pthread_create (&cons_thread, attr, consume ,NULL );
	// Ожидание завершения потоков
	pthread_join (cons_thread ,NULL) ;
	pthread_join (prod_thread ,NULL) ; return 0;
}

