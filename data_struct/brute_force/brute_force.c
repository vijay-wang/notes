#include "brute_force.h"

int brute_force(char* str,char* sub_str)
{
	int c = 0,d = 0;
	while(c < strlen(str) && d < strlen(sub_str))
	{
		if(str[c] == sub_str[d])
		{
			c++;
			d++;
		}
		else
		{
			d = 0;
			c -= d - 1;
		}
	}
	return d == strlen(sub_str) ? (c - d) : -1; 
}
