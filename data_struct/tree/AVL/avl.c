#include "avl.h"

static int
Max(int a,int b){
	return a > b ? a : b;
}


static int
Height(Position P){
	if(!P) return -1;
	return P -> height;
}



static AvlTree
SingleRotateWithRight(Position K2){
	Position K1 = K2 -> right;
	K2 -> right = K1 -> left;
	K1 -> left = K2;

	K2 -> height = Max(Height(K2 -> left),Height(K2 ->right)) + 1;
	K1 -> height = Max(Height(K1 -> right),K2 -> height) + 1;
	
	return K1;
}

static AvlTree
SingleRotateWithLeft(Position K2){
	Position K1 = K2 -> left;
	K2 -> left = K1 -> right;
	K1 -> right = K2;
	
	K2 -> height = Max(Height(K2 -> right),Height(K2 -> left)) + 1;
	K1 -> height = Max(Height(K1 ->left),K2 -> height) + 1;
	return K1;
}

static AvlTree 
DoubleRotateWithLeft(Position K2){
	K2 -> left = SingleRotateWithRight(K2 -> left);
	return SingleRotateWithLeft(K2);
}

static AvlTree
DoubleRotateWithRight(Position K2){
	K2 -> right = SingleRotateWithLeft(K2 -> right);
	return SingleRotateWithRight(K2);
}

AvlTree
Insert(Type X,AvlTree tree){
	/*创建新节点*/
	if(tree == NULL){
		tree =(AvlTree) malloc(sizeof(struct Avl));
		//printf("%p\n",tree);
		if(!tree) return NULL;
		tree -> data = X;
		tree -> left = tree -> right = NULL;
		tree -> height = 0;
	}
	/*向左边插入*/
	else
	if(X < tree -> data){
		tree -> left = Insert(X,tree -> left);
		/*进行右旋操作*/	
		if(Height(tree -> left)  - Height(tree -> right ) == 2)
			/*判断该进行单旋转还是双旋转*/	
			if(X < tree -> left -> data) tree = SingleRotateWithLeft(tree);
			else tree = DoubleRotateWithLeft(tree);  
	}
	/*向右边插入*/
	else
	if(X > tree -> data){
		tree -> right = Insert(X,tree -> right);
		/*进行左旋操作*/	
		if(Height(tree ->right)  - Height(tree -> left) == 2)
			/*判断该进行单旋转还是双旋转*/	
			if(X > tree -> right -> data) tree = SingleRotateWithRight(tree);
			else tree = DoubleRotateWithRight(tree);  
	
}
	
	tree -> height = Max(Height(tree -> left),Height(tree -> right)) + 1;	
	return tree;
}

void
PrintTree(AvlTree tree){
	if(!tree) return;
	PrintTree(tree -> left);
	printf("%d\n",tree -> data);
	PrintTree(tree -> right);
}

void
FreeTree(AvlTree tree){
	if(!tree) return;
	FreeTree(tree -> left);
	FreeTree(tree -> right);
	free(tree);
}

