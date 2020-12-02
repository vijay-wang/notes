#ifndef BTREE_H_
#define BTREE_H_

#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ORDER 5
#define MAX_ELE (ORDER - 1)
#define MIN_ORDER ceil(ORDER / 2)
#define MIN_ELE (MIN_ORDER - 1)

typedef struct btree* BTree;
typedef BTree BNode;
typedef int Type;

struct btree{
	int count;
	Type data[MAX_ELE];	
	BTree child[ORDER];
};

//错误处理
static void 
error_proc(const char* s);

//分配新结点
static BNode
alloc_node(void);

//二分查找元素X,找到返回下标，没找到返回-1
static int
findX(X,BNode node);

//初始化

#ifdef __cplusplus
}
#endif
 

#endif
