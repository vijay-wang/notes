#ifndef SPLAYTREE_H_
#define SPLAYTREE_H_
#include<stdio.h>
#include<stdlib.h>

struct tree;
typedef struct tree STree;
typedef int Type;

struct tree{
	STree* left;
	STree* right;
	Type data;
};


//插入操作
STree*
Insert(Type X,STree* T);

//左旋操作
static STree*
SingleRotateWithRight(STree* K2);

//右旋操作
static STree*
SingleRotateWithLeft(STree* K2);

//释放内存
void
FreeTree(STree* T);

//打印树
void
PrintTree(STree* T);
#endif
