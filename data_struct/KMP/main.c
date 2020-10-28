#include "kmp.h"

int main(void)
{
	char S_str[] = "望江楼，望江流，望江楼上望江流，江流千古，江楼千古";
	char T_str[] = "楼上望";
	int t = kmp(S_str,T_str);
	printf("%s",S_str + t );
//	char T_str[] = "abdabdefc";	
//	int next[strlen(T_str)];
//	next_(T_str,next);
//	for(int i = 0;i<strlen(T_str);i ++){
//		printf("%d",next[i]);		
//	}
	return 0;
}
