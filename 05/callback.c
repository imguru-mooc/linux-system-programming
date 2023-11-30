#include <stdio.h>


void aaa( void (*fp)(void) )
{
	printf("aaa()\n");
	if(fp!=0)
		fp();
}

//---------------------------------------------------------

void foo(void)
{
	printf("foo()\n");
}

void bar(void)
{
	printf("bar()\n");
}

int main()
{
	aaa(bar);
	return 0;
}
