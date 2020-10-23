#include "link_stack.h"

int main(void)
{
	Stack my_stack = CreateStack();
	int i = 100000000;
	while(i--)
	{
		push(my_stack,i);
	}
//	PrintStack(my_stack);
	FreeStack(my_stack);	
	return 0;
}
