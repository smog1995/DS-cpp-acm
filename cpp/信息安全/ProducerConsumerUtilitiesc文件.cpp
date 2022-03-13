ProducerConsumerUtilities.c:
#include <stdio.h>
#include <stdlib.h>

#include "ProducerConsumerUtilities.h"

void initProducerConsumerManager(ProducerConsumerManager_t *producerConsumerMgr) {
	sem_init(&producerConsumerMgr->mutex, 0, 1);//�ź�����ַ���̹߳����źų�ֵ
	sem_init(&producerConsumerMgr->full, 0, 0);//�źų�ֵΪ0��������һ��ʼΪ��
	sem_init(&producerConsumerMgr->empty, 0, BUFFER_SIZE);

	producerConsumerMgr->producerOffset = 0;
	producerConsumerMgr->consumerOffset = 0;
	producerConsumerMgr->bufferSize = BUFFER_SIZE;

	producerConsumerMgr->exit_flag = 0;
}

ProducerConsumerManager_t *createProducerConsumerManager() {
	ProducerConsumerManager_t *producerConsumerMgr = (ProducerConsumerManager_t *)malloc(sizeof(ProducerConsumerManager_t));

	if (producerConsumerMgr == NULL) {
		printf("Error: unable to create producerConsumerMgr\n");
		return NULL;
	}

	initProducerConsumerManager(producerConsumerMgr);

	return producerConsumerMgr;
}

void initThreadStruct(ThreadStruct_t *threadStruct, ProducerConsumerManager_t *producerConsumerMgr, int threadIdx) {
	threadStruct->producerConsumerMgr = producerConsumerMgr;//��ָ���������������ѹ���Ա
	threadStruct->threadIdx = threadIdx;//�߳�����ֵ
}

ThreadStruct_t *createThreadStruct(ProducerConsumerManager_t *producerConsumerMgr, int threadIdx) {
	ThreadStruct_t *threadStruct = (ThreadStruct_t *)malloc(sizeof(ThreadStruct_t));

	if (threadStruct == NULL) {
		printf("Error: unable to create ThreadStruct_t\n");
		return NULL;
	}

	initThreadStruct(threadStruct, producerConsumerMgr, threadIdx);

	return threadStruct;
}

void semWait(sem_t *sem) {
	int ret = sem_wait(sem);
	if (ret < 0)
	{
		perror("sem_wait fail!");
		exit(EXIT_FAILURE);
	}
}

void semSignal(sem_t *sem) {
	int ret = sem_post(sem);
	if (ret < 0)
	{
		perror("sem_post fail!\n");
		exit(EXIT_FAILURE);
	}
}
void semDestroy(sem_t* sem)
{
	int ret = sem_destroy(sem);
	if (ret < 0)
	{
		perror("sem_destroy run fail\n");
		exit(EXIT_FAILURE);
	}
}