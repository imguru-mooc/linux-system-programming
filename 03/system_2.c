#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int my_system(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if( pid == 0 )
	{
		execl("/bin/sh", "sh", "-c", command, (char *) 0);
		_exit(127);
	}
	else if( pid > 0 )
		waitpid(pid, &status, 0);
	else
		status = -1;
	return status;
}

int main()
{
	my_system("ls -i");
	printf("after\n");
	return 0;
}
