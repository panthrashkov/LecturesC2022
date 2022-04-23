#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "queue.h"



int main(void){

	push(1); push(2); push(3);
	printf("pop %d \n", pop());
	printf("pop %d \n", pop());
	printf("count in stack %d \n", get_count());

	enqueue(1.0);
	enqueue(2.0);
	enqueue(3.0);

	printf("dequeue %f \n", dequeue());
	printf("dequeue %f \n", dequeue());


}
