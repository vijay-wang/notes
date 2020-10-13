#ifndef ARR_ATACK_H_
#define ARR_ATACK_H_
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 100
struct stack;
typedef int DataType ;
typedef struct stack Stack; 
struct stack
{
	DataType data[MAXSIZE];
	int top; 
};
Stack* CreateStack(void);

void InitStack(Stack * stack);

int IsEmpty(Stack* stack);

int IsFull(Stack* stack);

void push(Stack* s,DataType data);

void pop(Stack* s);

void FreeStack(Stack * s);

void ErrProc(char str[]);

void PrintStack(Stack* s); 
#endif
