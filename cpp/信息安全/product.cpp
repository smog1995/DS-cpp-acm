Producer.h:
#ifndef __PRODUCER_HEADER__
#define __PRODUCER_HEADER__

#include <stdio.h>

void *producerThread(void *arg);

#endif

Producer.c:

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#include "ProducerConsumerUtilities.h"
#include "Producer.h"

#define MAX_RAND_NUMBER 9999999

void generateProduct(ProducerConsumerManager_t *producerConsumerMgr, int threadIdx) {
	sem_t *mutex = &(producerConsumerMgr->mutex);
	sem_t *full = &(producerConsumerMgr->full);
	sem_t *empty = &(producerConsumerMgr->empty);
	int productGenerated = rand() % MAX_RAND_NUMBER;

	semWait(empty);//before accessing buffer 
	semWait(mutex);4

	++producerConsumerMgr->remainProducts;
	producerConsumerMgr->buffer[producerConsumerMgr->producerOffset] = productGenerated;//随机生成一个数，在上面
	producerConsumerMgr->producerOffset = (producerConsumerMgr->producerOffset + 1) % producerConsumerMgr->bufferSize;

	printf("producer:%d, generate product:%d\n", threadIdx, productGenerated);

	semSignal(full);
	semSignal(mutex);//after accessing buffer
}

void *producerThread(void *arg) {
	ThreadStruct_t *curThreadStruct = (ThreadStruct_t *)arg;
	ProducerConsumerManager_t *producerConsumerMgr = curThreadStruct->producerConsumerMgr;

	srand(curThreadStruct->threadIdx);
	while (curThreadStruct->producerConsumerMgr->exit_flag == 0) {//当前有线程，没有退出，则进行睡眠（等待锁）
		generateProduct(producerConsumerMgr, curThreadStruct->threadIdx);
		sleep(WAIT_TIME_IN_SECOND);// wait WAIT_TIME_IN_SECOND seconds 
	}

	if (curThreadStruct->threadIdx == 0)
	{

		//producerConsumerMgr->remainProducts is zero indicates there are consumer threads waiting for product 
		while (producerConsumerMgr->remainProducts == 0) {
			do {
				generateProduct(producerConsumerMgr, curThreadStruct->threadIdx);
				sleep(1);
			} while (producerConsumerMgr->remainProducts != producerConsumerMgr->bufferSize);
		}
	}

	return arg;
}