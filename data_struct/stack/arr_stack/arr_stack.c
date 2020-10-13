#include "arr_stack.h"

//打印错误信息，并退出程序
void ErrProc(char str[])
{
	printf("%s\n",str);
}


//创建一个大小为MAXSIZE的栈
Stack* CreateStack(void)
{
	Stack * s = malloc(sizeof(Stack));
//	memset(s->data,0,sizeof(s->data));
	return s;
}

//初始化栈
void InitStack(Stack * stack)
{
	stack->top = -1;
}

//判断栈是否为空,返回真即为空，返回假即为非空
int IsEmpty(Stack* stack)
{
	return stack->top == -1;
}

//判断栈是否已满,返回真表示已满，返回假表示未满
int IsFull(Stack* stack)
{
	return stack->top == (MAXSIZE-1);
}

//元素入栈
void push(Stack* s,DataType data)
{
	if(IsFull(s))	ErrProc("栈已满，不能执行push操作");	
	else
	{
		s->top++;
		s->data[s->top] = data;
	}
}

//元素出栈
void pop(Stack* s)
{
	if(IsEmpty(s))	ErrProc("栈为空，不能执行pop操作");	
	else s->top--;
}

//释放栈所申请的内存
void FreeStack(Stack * s)
{
	free(s);
	printf("申请的动态内存已经释放\n");
}

//打印栈
void PrintStack(Stack* s)
{
	int index = 0;
	while(s -> top != -1 && index <= s -> top)
	{
		printf("第%d个元素：%d\n",index,s -> data[index]);
		index++;
	}
}
