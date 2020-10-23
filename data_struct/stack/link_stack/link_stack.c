#include "link_stack.h"


void PrintStack(Stack s)
{
	int i = 0;
	while(s -> next) 
	{
		printf("第%d个元素：%d\n",i++ ,s -> next -> data);
		s = s -> next;
	}
}

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


//void InitStack(Stack s)
//{
//	s -> next = (void*)0;
//}

//返回真表示栈为空，返回假表示栈不为空
int IsEmpty(Stack s)
{
	return s -> next == (void*)0;
}

//s为栈顶结点
void push(Stack s,DataType data)
{
	Stack new_stack = malloc(sizeof(struct Node));	
	if(!new_stack) 
	{
		ErrProc("out of space!\n");
		exit(EXIT_FAILURE);
	}
	new_stack -> next = s -> next;
	new_stack -> data = data;
	s -> next = new_stack;
}

//删除栈顶元素，返回栈顶结点
void pop(Stack s)
{
	if(IsEmpty(s))	
	{
		ErrProc("stack is empty!\n");
		exit(EXIT_FAILURE);
	}	
	Stack tmp = s -> next;
	s -> next = s -> next -> next;
	free(tmp);
}

//返回栈顶结点的指针
Position top(Stack s)
{
	if(s -> next) return s -> next;
	return (void*)0;
}

void FreeStack(Stack s)
{
	int i = 0;
	Stack tmp = s;
	while(s -> next)
	{
		tmp = s -> next;
		free(s);
		s = tmp;	
//		printf("free%d\n",++i);
	}
	free(s);
}

