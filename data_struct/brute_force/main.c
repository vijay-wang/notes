#include "brute_force.h"

int main(void)
{

	char str[] = "望江楼，望江流，望江楼上望江流，江流千古，江流千古";
	char sub_str[] = "千古";
	printf("%s",str + brute_force(str,sub_str));
	return 0;
}
