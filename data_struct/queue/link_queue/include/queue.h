#ifndef QUEUE_H_
#define QUEUE_H_
#include<stdio.h>
#include<stdlib.h>

struct queue;
typedef struct queue* Queue;
typedef int ElementType;
struct queue
{
	ElementType data;
	Queue next;	
};

typedef struct
{
	Queue front;
	Queue rear;
}LinkQueue;

//创建队列
Queue CreateQueue(void);

//初始化队列,返回头尾指针结构体
LinkQueue* InitQueue(Queue q);

//判断链队是否为空
int IsEmpty(LinkQueue* q);

//入队
void EnQueue(LinkQueue* link_queue,ElementType data);

//出队
void DeQueue(LinkQueue* link_queue);

//释放队列
void FreeQueue(Queue q,LinkQueue* link_queue);

//打印队列
void PrintQueue(Queue q);
#endif

