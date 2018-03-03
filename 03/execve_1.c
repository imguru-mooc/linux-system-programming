#include <unistd.h>
#include <stdio.h>
int main()
{
	char *argv[] = { "ls", (char*)0 };
	execve( "/bin/ls", argv, 0 );
	printf("after\n");
	return 0;
}
