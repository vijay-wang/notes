#include<stdio.h>
#include<stdlib.h>

int test(int N)
{
	if(N<=1)
		return 1;
	else
		return test(N-1) + test(N-1);
}

int main()
{
	printf("%d",test(3));
	return 0;
}
