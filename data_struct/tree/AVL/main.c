#include "avl.h"
#include<time.h>

int main(void){
	AvlTree	my_tree = Insert(20,NULL);

	srand((unsigned int)time(NULL));	
	int a ;
	for(int i = 10;i < 30;i++){
		a = rand()%20 + 10;
		Insert(a,my_tree);
	}
	//printf("%p\n",my_tree);
	PrintTree(my_tree);
	FreeTree(my_tree);
	return 0;
}
