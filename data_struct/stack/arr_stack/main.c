#include "arr_stack.h"
#include<unistd.h>
#include<sys/types.h>
int main(void)
{
	Stack* my_stack = CreateStack();
	InitStack(my_stack);
	int i = 50;
	while(i--)
	{
		push(my_stack,i);
	}	
	PrintStack(my_stack);
	FreeStack(my_stack);
	printf("%d\n",getpid());
	pause();
	return 0;
}
