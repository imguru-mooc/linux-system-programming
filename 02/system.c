#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret;
	ret = system("aaa");
	printf("ret = %d\n", ret>>8 );
	return 0;
}
