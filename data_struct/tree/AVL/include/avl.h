#ifndef AVL_H_
#define AVL_H_
#include<stdio.h>
#include<stdlib.h>

struct Avl;
typedef struct Avl* AvlNode;
typedef AvlNode AvlTree;
typedef AvlNode Position;
typedef int Type;

struct Avl{
	int height;
	AvlNode left;
	AvlNode right;
	Type data;
};

//平衡二叉查找树的插入操作
AvlNode
Insert(Type X,AvlTree tree);

//左旋操作
static AvlTree
SingleRotateWithLeft(Position K2);

//右旋操作
static AvlTree
SingleRotateWithRight(Position K2);

//获取树的高度
static int
Height(Position P);

//右旋的双旋转操作
static  AvlTree
DoubleRotateWithRight(Position K2);

//左旋的双旋转操作
static AvlTree
DoubleRotateWithLeft(Position K2);

//用于比较两个数大小，返回较大的哪一个
static int
Max(int a,int b);

//打印平衡二叉树
void
PrintTree(AvlTree tree);

void
FreeTree(AvlTree tree);
#endif

