#ifndef	KMP_H_
#define KMP_H_
#include<stdio.h>
#include<string.h>
void next_(const char* const T,int* const next);

int kmp(const char* const S,const char* const T);

#endif
