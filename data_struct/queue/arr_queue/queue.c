#include "queue.h"

Queue CreateQueue(void)
{
	Queue q = malloc(sizeof(struct queue));
	if(!q) printf("out of space!");
	return q;
}


void InitQueue(Queue q)
{
	q -> front = -1;
	q -> rear  = -1;
	q -> capacity = 0;
}

int IsEmpty(Queue q)
{
	return q -> capacity == 0;	
}

int IsFull(Queue q)
{
	return q -> capacity == MAXSIZE;
}

void EnQueue(Queue q,DataType data)
{
	if(IsFull(q))
	{
		printf("队列已满!\n");
		return;
	}
	q -> rear++;
	q -> rear %= MAXSIZE;
	q -> data[q -> rear] = data;
	q -> capacity ++; 
}

void DeQueue(Queue q)
{
	if(IsEmpty(q))
	{
		printf("队列为空，不能执行出队操作");
		return;
	}
	q -> front ++;
	q -> front %= MAXSIZE;
	q -> capacity --;
}


void FreeQueue(Queue q)
{
	free(q);
}

void PrintQueue(Queue q)
{
	if(IsEmpty(q)) return;
	int i = q -> capacity;
	int index = q -> rear;
	while(i)
	{
		if(!index)
		{
			printf("第%d个元素：%d\n",i--,q -> data[index]);	
			index = MAXSIZE - 1;
			continue;
		}
		printf("第%d个元素：%d\n",i--,q -> data[index]);	
		index --;
	}
}
