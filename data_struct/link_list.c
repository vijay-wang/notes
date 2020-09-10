#include "link_list.h"

List create(void)
{
	List phead=(List)malloc(sizeof(struct Node));
	phead->next=nullptr;
	return phead;
}

int IsEmpty(List phead)
{
	return phead->next==NULL;
}

int add(List phead)
{
	List p,ptemp;
	p=(List)malloc(sizeof(struct Node));
	p->next=nullptr;
	//ptemp=phead->next;
	while(phead->next)	phead=phead->next;
	phead->next=p;

}

int
IsLast(Position p)
{
	return p->next==NULL;
}

Position
Find(int X,List L)
{
	while(L->next && L->next->data->stu_num == X)
		return L->next;
}

