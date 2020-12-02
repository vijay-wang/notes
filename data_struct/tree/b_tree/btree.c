#include "bree.h"

//错误处理
static void 
error_proc(const char* s){
	printf("ERROR:in func:%s\n",s);
	exit(EXIT_FAILURE);
}

//分配新结点
static BNode
alloc_node(void){
	BNode node = (BNode)malloc(sizeof struct btree);
	if(!node) error_proc("alloc_node:out of space!");
	node -> count = 0;
	for(int i = 0;i < node -> ORDER;i++) node -> children[i] = NULL;	
	return node;
}

//二分查找元素X,找到返回下标，没找到返回-1
static int
findX(X,BNode node){
	int low = 0;
	int high = node -> count;
	int mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(node -> data[mid] == X) return mid
		else if(X < node -> data[mid]) high = mid - 1;
		else low = mid + 1;	
	}
	return -1;
}
