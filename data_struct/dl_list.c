
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

void
PrintListPre(DbList L);
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
	P -> next =nullptr;
	while(L -> next) L = L -> next;
	L -> next = P;
	P -> prior = L;
	return P;
}

void
PrintList(DbList L)
{
	int count=0;
	DbList temp = L -> next;
	while(temp)
	{
		printf("第%d个元素:%d\n",count++,temp -> data);
		temp = temp -> next;
	}	
};

//=======================================================================
int main(void)
{
	DbList P = InitDbList();
	int i=100;
	while(i--)
		Add(rand()%100+1,P);
	PrintList(P);
	
	PrintList(P);

	DeleteList(P);
	return 0;
}

