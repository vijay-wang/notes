#ifndef LINK_LIST_H__
#define LINK_LIST_H__
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* List;
typedef struct Node* Position;

struct Stu
{
	int score;
	int stu_num;
	char name[12];
};

struct	Node
{
	struct Stu* data;
	Node* next;
};

//创建头结点
List create(void);

//返回true表示链表不为空，返回0表示链表为空
int IsEmpty(List phead);

//添加新节点
int add(List phead);

//return true if P is the last position
int
IsLast(Position);

//find the first element x
Position
Find(int x,List L);
#end

// 
