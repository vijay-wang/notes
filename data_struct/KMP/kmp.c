#include "kmp.h"
void next_(const char* const T,int* const next){
	int i = 1,j = 0;
	int str_len = strlen(T);
	next[0] = 0;
	next[1] = 1;
	while(i < str_len){
		if(j == 0 || T[i-1] == T[j-1]){
			j++;
			i++;
			next[i - 1] = j;
		}
		else j = next[j - 1]; 
	}
		
}


int kmp(const char* const S,const char* const T)
{
	int i = 0,j = 0;
	int S_len = strlen(S);
	int T_len = strlen(T);
	int next[strlen(T)];
	next_(T, next);
	while(j < T_len && (S_len - i) >= T_len){
		if(S[i] == T[j]){
			i ++ ;
			j ++ ;
		}
		else{
			j = next[j];
			i ++;
		}		
			 
	}
	return i <= (S_len - T_len) ? (i - j) : -1;
}
