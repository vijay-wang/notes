#include "binary_search_tree.h"


Tree
insert(ElementType data,Tree tree){
	if(tree){
		if(data < tree -> data){
			tree -> left = insert(data,tree -> left); 
		}
		else if(data > tree -> data){
			tree -> right = insert(data,tree -> right);
		}
	}	
	else{
		tree =  malloc(sizeof(struct Node));
		if(!tree) return NULL;
		tree -> data = data;
		tree -> left = tree -> right = NULL ;
	}
	return tree;
}


Position
find_min(Tree tree){
	if(tree)
		while(tree -> left)
			tree = tree -> left;
	return tree;
}


Position
find_max(Tree tree){
	if(tree)
		while(tree -> right)
			tree = tree -> right;
	return tree;

}

Position
find(ElementType X,Tree tree){
	if(!tree) return NULL;
	if(X < tree -> data)
		find(X,tree -> left);
	else if(X > tree -> data)
		find(X,tree -> right);
	else
		return tree;
}

Tree
free_tree(Tree tree){
	if(tree){
		free_tree(tree -> left);
		free_tree(tree -> right);
		free(tree);
	}
	return NULL;
}


void 
print_tree(Tree tree){
	if(!tree) return;
	print_tree(tree -> left);
	printf("%d\n",tree -> data);
	print_tree(tree -> right);
}


Tree
delete_X(ElementType X,Tree tree){
	if(!tree) return NULL;
	else if(X < tree -> data) tree -> left = delete_X(X,tree -> left);
	else 
	if(X > tree -> data) tree -> right = delete_X(X,tree -> right);
	else
	if(tree ->left && tree -> right){
		tree -> data = (find_min(tree -> right)) -> data;
		tree -> right = delete_X(tree -> data,tree -> right);	
	}
	else{
		Tree tmp = tree;
		if(tree -> left) tree = tree -> left; 
		else if(tree -> right) tree = tree -> right; 
		else tree = NULL;
		free(tmp);
	} 
	return tree;
}
