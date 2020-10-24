#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

struct Node;
typedef struct Node* Tree;
typedef int ElementType;
struct Node
{
	ElementType data;
	Tree left;
	Tree right; 
};

#endif
