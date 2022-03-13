#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ProducerConsumerUtilities.h"
#include "Consumer.h"
#include "Producer.h"

#define PRODUCER_NUMBER 2
#define CONSUMER_NUMBER 10

int main(int argc, char *argv[]) {
	int idx = 0;
						//指针
	ThreadStruct_t *producerThreadStructPtr = (ThreadStruct_t *)malloc(sizeof(ThreadStruct_t) *PRODUCER_NUMBER);//创建线程，堆分配生产者个数*线程结构大小的空间
	ThreadStruct_t *consumerThreadStructPtr = (ThreadStruct_t *)malloc(sizeof(ThreadStruct_t) *CONSUMER_NUMBER);//消费者
	ProducerConsumerManager_t *producerConsumerMgr = createProducerConsumerManager();//生产者管理
	if (NULL == producerThreadStructPtr || NULL == consumerThreadStructPtr || NULL == producerConsumerMgr)
	{
		perror("malloc fail!\n");//分配失败
		exit(EXIT_FAILURE);
	}

	for (idx = 0; idx < PRODUCER_NUMBER;++idx) {
		ThreadStruct_t *curProducerThreadStruct = producerThreadStructPtr + idx;//创建一个线程结构类型指针指向生产者线程作为当前值
		initThreadStruct(curProducerThreadStruct, producerConsumerMgr, idx);//将每一个成员初始化
		pthread_create(&curProducerThreadStruct->tid, NULL, producerThread, (void *)curProducerThreadStruct);//创建线程
	}                         //线程标识符（类似pid_t, 是pthread_t） NULL为线程属性   线程运行函数（指针）      前一个函数的参数(这里是生产者线程）

	for (idx = 0; idx < CONSUMER_NUMBER; ++idx) {
		ThreadStruct_t *curConsumerThreadStruct = consumerThreadStructPtr + idx;
		initThreadStruct(curConsumerThreadStruct, producerConsumerMgr, idx);
		pthread_create(&curConsumerThreadStruct->tid, NULL, consumerThread, (void *)curConsumerThreadStruct);
	}

	do {
		char aChar = getchar();
		if (aChar == 'q')
		{
			producerConsumerMgr->exit_flag = 1;
		}
	} while (producerConsumerMgr->exit_flag == 0);


	//Wait producer threads exit
	for (idx = 0; idx < PRODUCER_NUMBER; ++idx) {
		ThreadStruct_t *curProducerThreadStruct = producerThreadStructPtr + idx;
		pthread_join(curProducerThreadStruct->tid, NULL);//线程号，等待一个线程的结束
	}

	//Wait consumer threads exit
	for (idx = 0; idx < CONSUMER_NUMBER; ++idx) {
		ThreadStruct_t *curConsumerThreadStruct = consumerThreadStructPtr + idx;
		pthread_join(curConsumerThreadStruct->tid, NULL);
	}
	free(producerThreadStructPtr);
	free(consumerThreadStructPtr);
	semDestroy(&(producerConsumerMgr->mutex));
	semDestroy(&(producerConsumerMgr->full));
	semDestroy(&(producerConsumerMgr->empty));
	free(producerConsumerMgr);
	return 1;
}