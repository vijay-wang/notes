#ifndef LINK_STACK_H_
#define LINK_STACK_H_

//所需头文件
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* Stack;
typedef Stack Position;
typedef int DataType;

//栈的结构体定义
struct Node
{
	DataType data;
	Stack next;
}

//错误处理
void ErrProc(char str[]);

//栈的创建
Stack CreateStack(void);

//栈的初始化
void InitStack(Stack s);

//判断栈是否为空
int IsEmpty(Stack s);

//入栈,返回新入栈的元素位置
Position push(Stack s);

//出栈,返回最后一个元素的位置
Position pop(Stack s);

//栈的销毁，释放动态申请的内存
void FreeStack(Stack s);

//返回栈顶的元素
Position top(Stack s);

#endif 
