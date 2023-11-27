#include <stdio.h>
int main()
{
	int a;
	char buff[1234];
	printf("%ld\n", sizeof(buff));
	printf("%ld\n", sizeof buff);
	printf("%ld\n", sizeof(int));
	return 0;
}
