#ifndef QUEUE_H_
#include<stdio.h>
#include<stdlib.h>
#define QUEUE_H_
#define MAXSIZE 100

struct queue;
typedef struct queue* Queue;
typedef int DataType;

struct queue
{
	DataType data[MAXSIZE];
	int front;
	int rear;
	int capacity;
};

//创建队列，返回队列指针
Queue CreateQueue(void);

//队列为空，返回真
int IsEmpty(Queue q);

//队列已满返回真
int IsFull(Queue q);

//入队
void EnQueue(Queue q,DataType data);

//出队,返回删除的元素
void DeQueue(Queue q);

//初始化队列结构体
void InitQueue(Queue q);

//释放队列动态申请的内存
void FreeQueue(Queue q);

void PrintQueue(Queue q);
#endif
