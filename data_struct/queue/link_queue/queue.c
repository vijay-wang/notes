#include "queue.h"



Queue CreateQueue(void)
{
	Queue queue = malloc(sizeof(struct queue));
	if(queue) return queue;
	printf("out of space!");
	return queue;
}


LinkQueue* InitQueue(Queue q)
{
	q -> next = NULL;
	LinkQueue* link_queue = malloc(sizeof(LinkQueue));
	if(!link_queue)	return link_queue;	
	link_queue -> front = link_queue -> rear = q;
	return link_queue;
}


int IsEmpty(LinkQueue* q)
{
	return q -> front == q -> rear; 
}


void EnQueue(LinkQueue* link_queue,ElementType data)
{
	Queue new_node = malloc(sizeof(struct queue));
	if(!new_node) return;
	new_node -> data = data;
	new_node -> next = NULL;  
	link_queue -> rear -> next = new_node;
	link_queue -> rear = new_node;		
}



void DeQueue(LinkQueue* link_queue)
{
	if(IsEmpty(link_queue))	return;
	Queue tmp = link_queue -> front -> next;
	if(tmp == link_queue -> rear)	link_queue -> rear = link_queue -> front;
	link_queue -> front -> next = tmp -> next;
	free(tmp);
	printf("出栈成功\n");

}


void FreeQueue(Queue q,LinkQueue* link_queue)
{
	Queue tmp = q;
	free(link_queue);
	while(q -> next)
	{
		tmp = q -> next;
		free(q);
		q = tmp;
	}
	free(q);
}



void PrintQueue(Queue q)
{
	int i = 0;
	while(q -> next)
	{
		printf("第%d个元素：%d\n",i++,q->next->data);
		q = q -> next;	
	}
}
