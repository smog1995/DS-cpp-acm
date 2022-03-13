#ifndef __CONSUMER_HEADER__
#define __CONSUMER_HEADER__

#include <stdio.h>

void *consumerThread(void *arg);

#endif
Consumer.c:

#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#include "Consumer.h"
#include "ProducerConsumerUtilities.h"


void getProduct(ProducerConsumerManager_t *producerConsumerMgr, int threadIdx) {
	sem_t *mutex = &(producerConsumerMgr->mutex);
	sem_t *full = &(producerConsumerMgr->full);
	sem_t *empty = &(producerConsumerMgr->empty);
	int productGetted;

	semWait(full);//before accessing buffer
	semWait(mutex);

	productGetted = producerConsumerMgr->buffer[producerConsumerMgr->consumerOffset];
	producerConsumerMgr->consumerOffset = (producerConsumerMgr->consumerOffset + 1) % producerConsumerMgr->bufferSize;
	--producerConsumerMgr->remainProducts;
	printf("Consumer:%d, get product:%d\n", threadIdx, productGetted);

	semSignal(empty);
	semSignal(mutex);//after accessing buffer
}

void *consumerThread(void *arg) {
	ThreadStruct_t *curThreadStruct = (ThreadStruct_t *)arg;
	ProducerConsumerManager_t *producerConsumerMgr = curThreadStruct->producerConsumerMgr;

	while (curThreadStruct->producerConsumerMgr->exit_flag == 0) {
		getProduct(producerConsumerMgr, curThreadStruct->threadIdx);
		sleep(WAIT_TIME_IN_SECOND);// wait WAIT_TIME_IN_SECOND seconds 
	}

	return arg;
}
