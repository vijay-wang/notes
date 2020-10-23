#include "queue.h"

int main(void)
{
	Queue my_queue = CreateQueue();
	InitQueue(my_queue);
	int i = 87;
	while(i--)	
	{
		EnQueue(my_queue,i);
	}
	PrintQueue(my_queue);
	FreeQueue(my_queue);
	return 0;
}
