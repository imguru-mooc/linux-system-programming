#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int global=6;

int main()
{
	pid_t pid;
	pid = fork();

	if( pid == 0 )
	{
		printf("child  : global=%d\n", ++global);
		printf("child  : &global=%p\n", &global);
		exit(0);
	}
	wait(0);
	printf("parent : global=%d\n", global);
	printf("child  : &global=%p\n", &global);
	return 0;
}
