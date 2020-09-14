#ifndef D_CIRCULAR_LINKED_LIST_
#define D_CIRCULAR_LINKED_LIST_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node* List;
typedef List Position;

Struct Node
{
	int data;
	List prior;
	List next;
}

//初始化双向循环链表头结点
List
InitList(void);

//销毁双向循环链表，释放堆内存,L为链表头结点
void
DeleteList(List L);

//添加节点，其中L为链表头结点，Position为任一一个位置
Position
Add(int X,Position,List L);
#endif
