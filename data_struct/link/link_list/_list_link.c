#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#define nullptr (void*)0 

typedef struct Node* DbList;
typedef DbList Position;

struct Node
{
	DbList prior;
	int data;
	DbList next;
};
//=====================================================================
DbList
InitDbList(void);

void
DeleteList(DbList L);

Position
Add(int X,DbList L);

void
PrintList(DbList L);
//======================================================================
DbList
InitDbList(void)
{
	 DbList P=(DbList)malloc(sizeof(struct Node));
	 P -> prior = P -> next = nullptr;
}

void
DeleteList(DbList L)
{
	DbList temp;
	while(L -> next)
	{
		temp = L -> next ->next;
		free(L -> next);
		L -> next = temp;
	}
	free(L);

}

Position
Add(int X,DbList L)
{
	Position P;
	P = malloc(sizeof(struct Node));
	P -> data = X;
	while(L -> next) L = L -> next;
	L -> next = P;
	P -> prior = L;
	return P;
}

void
PrintList(DbList L)
{
	int count=0;

	while(L -> next)
	{
		printf("第%d个元素:%d\n",count++,L -> next -> data);
		L -> next = L-> next -> next;
	}

	while(L -> prior)
	{
		printf("第%d个元素:%d\n",count--,L -> prior -> data);
		L -> prior = L-> prior -> prior;
	}
};
//=======================================================================
int main()
{
	DbList P = InitDbList();
	int i=100;
	while(i--)
		Add(rand()%100+1,P);
	PrintList(P);
	DeleteList(P);
	return 0;
}
