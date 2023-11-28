#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
	char *argv[] = { "ls", (char*)0 };
	printf("prompt> ls\n");
	if( fork() == 0 )
		execve( "/usr/bin/ls", argv, 0 );
	wait(0);
	printf("prompt> \n");
	return 0;
}
