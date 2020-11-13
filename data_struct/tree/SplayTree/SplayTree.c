#include "SplayTree.h"

STree*
Insert(Type X,STree* T){
	if(!T){
		T = (STree*)malloc(sizeof(struct tree));
		T -> data = X;
		T -> left = T -> right = NULL;
	}
	else
	if(X < T -> data){
		T -> left = Insert(X,T -> left);	
		T = SingleRotateWithLeft(T);
	}
	else
	if(X > T -> data){
		T -> right = Insert(X,T -> right);	
		T = SingleRotateWithRight(T);
	}
	return T;
}

static STree*
SingleRotateWithRight(STree* K2){
	STree* K1 = K2 -> right;
	K2 -> right = K1 -> left;
	K1 -> left = K2;
	return K1;
}

static STree*
SingleRotateWithLeft(STree* K2){
	STree* K1 = K2 -> left; 
	K2 ->  left = K1 -> right;
	K1 -> right = K2;
	return K1;
}

void
FreeTree(STree* T){
	if(!T) return;
	FreeTree(T -> left);
	FreeTree(T -> right);
	free(T);
}

void
PrintTree(STree* T){
	if(!T)	return;
	printf("%d\n",T -> data);
	PrintTree(T -> left);
	PrintTree(T -> right);
}

