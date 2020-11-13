#include "binary_search_tree.h"
#include<time.h>
int main(void){
	int a;
	Tree my_tree = insert(10,NULL);
	srand((unsigned int)time(NULL));
	for(int i = 0;i < 20;i++){
		a = rand()% 21 + 0;
		insert(a,my_tree);
	}
	print_tree(my_tree);
//	printf("最小元素：%d\n",((Tree)find_min(my_tree)) -> data);
//	printf("最大元素：%d\n",((Tree)find_max(my_tree)) -> data);
	delete_X(15,my_tree);
	delete_X(2,my_tree);
	delete_X(7,my_tree);
	delete_X(17,my_tree);
	printf("================\n");
	print_tree(my_tree);
	free_tree(my_tree);
		
	return 0;
}
