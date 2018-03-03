#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int local=10;
	pid_t pid;
	pid = fork();

	if( pid == 0 )
	{
		printf("child  : local=%d\n", ++local);
		exit(0);
	}
	wait(0);
	printf("parent : local=%d\n", local);
	return 0;
}
