#include <unistd.h>
#include <stdio.h>
int main()
{
	char *argv[] = { "ls", (char*)0 };
	execve( "/usr/bin/ls", argv, 0 );
	//printf("after\n");
	printf("prompt>");
	return 0;
}
