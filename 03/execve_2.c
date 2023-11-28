#include <unistd.h>
#include <stdio.h>
int main()
{
	char *argv[] = { "ls", (char*)0 };
	printf("prompt> ls\n");
	execve( "/usr/bin/ls", argv, 0 );
	printf("prompt> \n");
	return 0;
}
