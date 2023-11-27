#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	printf("no. of args = %d\n", argc);

	for(i=0; i<argc; i++)
		printf("argv[%d]=%s\n", i, argv[i]);

	return argc;
}

