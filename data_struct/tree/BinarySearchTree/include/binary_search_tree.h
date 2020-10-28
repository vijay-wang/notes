#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* Tree;
typedef Tree Position;
typedef int ElementType;
struct Node{
	ElementType data;
	Tree left;
	Tree right; 
};

//如果插入失败，返回NULL
Tree
insert(ElementType data,Tree tree);

//返回最小元素的指针
Position
find_min(Tree tree);

//返回最大元素的指针
Position
find_max(Tree tree);

//返回元素X的位置
Position
find(ElementType X,Tree tree);

//销毁树
Tree
free_tree(Tree tree);

//打印树
void 
print_tree(Tree tree);

//删除元素X
Tree
delete_X(ElementType X,Tree tree);
#endif
