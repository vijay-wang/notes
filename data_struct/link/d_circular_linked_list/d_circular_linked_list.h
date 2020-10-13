#include "d_circular_linked_list.h"

//初始化双向循环链表，返回头结点
List
InitList(void)
{
	List L = malloc(sizeof(struct Node));
	L -> prior = L;
	L -> next = L;
}

void
DeleteList(List L)
{
	List tmp = L;
	while(tmp -> next != L )
	{
		
	}	
}

int main(void)
{

	return 0;
}
