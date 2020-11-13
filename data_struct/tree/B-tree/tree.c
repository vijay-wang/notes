#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//使用格式 出错的函数名:错误描述
static void
error_print(const char* s){
	printf("ERROR:in func:%s\n",s);
	exit(EXIT_FAILURE);
}

//动态申请一个结点
static BNode
alloc_node(void){
	BNode node = (BNode)malloc(sizeof(struct tree));
	if(!node) error_print("alloc_node:out of space!"); 
	//初始化结点成员children为NULL
	for(int i = 0;i < ORDER;i ++) node -> children[i] = NULL;
	memset(node -> data,0,sizeof node -> data);  
	node -> amount = 0;
	return node;
}

//使用data初始化一个B树
//传入null则初始化一棵空树
BTree
InitBTree(const ElementType* data){
	if(!data) return alloc_node(); 
	BTree tree = alloc_node(); 
	int len_of_data = (sizeof data) / (sizeof(ElementType));
	for(int i = 0;i < len_of_data;i++){
		Insert(data[i],tree);
	} 
	return tree;
}

//在结点中对元素X进行二分查找，如果没有找到则返回-1
//如果找到，则返回元素所在数组的下标
static int
find(const ElementType X,const BNode node){
	int low = 0;
	int high = node -> amount - 1;
	int mid = (low + high) / 2;
	
	while(1){
		if(X == node -> data[mid]) return mid;
		if(low == high)	return -1;
		if(X < node -> data[mid]){
			high = mid - 1;
			mid = (low + high) / 2;
		}	
		else{
			low = mid + 1;
			mid = (low + high) / 2;
		}		
	}
	return -1;	
}

//查找元素X，如果没有找到则返回NULL，
//如果找到则返回元素所在结点指针
BNode
FindX(const ElementType X,const BTree tree){
	if(!tree) return tree;
	for(int i = 0;i < tree -> amount;i ++){
		if(X == tree -> data[i]) return tree;		 
		else
		if(X < tree -> data[i]) FindX(X,tree -> children[i]);
		else FindX(X,tree -> children[i + 1]);
	}
}

//当元素数量超过阶数时进行分裂
static BTree
split_b_tree(const ElementType X,BNode T){
	BNode left = (BNode)alloc_node();
	BNode right = (BNode)alloc_node();
	return NULL;
}

//查找元素X插入到node结点的孩子结点的位置
static int
find_insert_pos(const ElementType X,const BNode node){
	int low = 0;
	int high = node -> amount - 1;
	int mid = (low + high) / 2;
	
	while(1){
		if(X == node -> data[mid]) return mid;
		if(low == high)	return -1;
		if(X < node -> data[mid]){
			high = mid - 1;
			mid = (low + high) / 2;
		}	
		else{
			low = mid + 1;
			mid = (low + high) / 2;
		}		
	}
	return mid;	

}

//向未满的结点中插入元素
static BNode
insert_non_full(ElementType X,BNode node){
	//查找插入X的位置
	int i = node -> amount - 1;
	for(i;i >= 0;i --){
		if(X < node -> data[i]){
			node -> data[i + 1] = node -> data[i];
			node -> children[i + 2] = node -> children[i + 1];
		}
		else{
			node -> data[i + 1] = X;
			node -> children[i + 2] = NULL;
			return node;
			break;
		}
	}	
	/*考虑到边界问题，如果X小于node -> data[0]，此时i应该等于
	-1。那么直接在node -> data[0]处插入结点*/
	if(i == -1){
		node -> data[0] = X;
		node -> children[1] = children[0];
		node -> children[0] = NULL;
	}
	return node;
}

//插入元素X
BTree
Insert(const ElementType X,BTree T){
	if(!T) error_print("Insert:please initialize BTree firstly by using function InitBTree()!");   		
	/*在结点中查找元素X，如果找到则忽略元素X
	，不进行插入操作。如果没找到元素X,则进行插入操作*/
	if(find(X,T) == -1){
		//如果结点的第一个孩子结点为null，则结点为叶节点
		if(!T -> children[0]){
			/*如果叶节点已满，先进行分裂操作，再进行插
			入。*/
			if(T -> amount == MAX_ELEMENT){
				split_b_tree(X,T);
				insert_non_full(T);
			}
			//如果叶节点未满，直接进行插入操作
			else insert_non_full(X,T);
		}
		//如果结点的第一个孩子结点不为null，则结点为非叶结点
		else{
			//查找元素插入位置
			int insert_pos = find_insert_pos(X,T);
			//分两种情况，因为要考虑边界问题
			if(X < T -> data[insert_pos]) Insert(X,T -> children[insert_pos]);
			else Insert(X,T -> children[insert_pos + 1]);
		}

	}

}

