#include "link_stack.h"



void ErrProc(char str[])
{
	printf("%s",str);
}

Stack CreateStack(void)
{
	Stack my_stack = malloc(sizeof(struct Node));
	if(!my_stack)
	{
		ErrProc("out of space!\n");
		return my_stack;
	}
	my_stack -> next = (void*)0;
	return my_stack;
}

void InitStack(Stack s)
{
	s -> next = (void*)0;
}

//返回真表示栈为空，返回假表示栈不为空
int IsEmpty(Stack s)
{
	return s -> next == (void*)0;
}

//s为栈顶结点，只能传入栈顶结点，大量push能提高效率
Position push(Stack s,DataType data)
{
	Stack new_stack = malloc(sizeof(struct Node));	
	if(!new_stack) 
	{
		ErrProc("out of space!\n");
		return new_stack;
	}
	new_stack -> next = (void*)0;
	new_stack -> data = data;
	s -> next = new_stack;
	return new_stack;
}

//删除栈顶元素，返回栈顶结点
Position pop(Stack s)
{
	if(IsEmpty(s))	
	{
		ErrProc("stack is empty!\n");
	}	
	while(s -> next -> next) s = s -> next;
	free(s -> next);
	s -> next = (void*)0;
	return s;
}

Position top(Stack s)
{
	while(s -> next != (void*)0)	s = s -> next;
	return s;
}


