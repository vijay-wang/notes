#include "queue.h"

int main(void)
{
	Queue my_queue = CreateQueue();
	LinkQueue* link_queue = InitQueue(my_queue);
	int i = 100;
	while(i)
	{
		EnQueue(link_queue,i--);
	}
	PrintQueue(my_queue);
	int j=107;
	while(j--)
	{
		DeQueue(link_queue);
	}
	FreeQueue(my_queue,link_queue);
	return 0;
}
