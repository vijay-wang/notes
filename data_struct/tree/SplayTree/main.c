#include "SplayTree.h"
#include<time.h>
int main(void){
//	STree* my_tree = Insert(4,NULL);
	STree* my_tree = NULL;
	srand((unsigned int)time(NULL));
//	int a[10] = {4,12,15,8,11,2,5,18,7,3};
	int a[6];
	for(int i = 0;i < 6;i ++){
		a[i] = rand() % 6 + 0;
		printf("%d====\n",a[i]);
		my_tree = Insert( a[i] ,my_tree);
	}
	
	PrintTree(my_tree);
	
	FreeTree(my_tree);
	return 0;
}
