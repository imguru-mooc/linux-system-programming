#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 20 

int main() 
{
	int fd[2];
	int pid;
	char msgout[MSGSIZE] = "Hello, world\n";
	char msgin[MSGSIZE];

	if(pipe(fd)==-1)
	{
		perror("pipe()");
		exit(1);
	}
	if ((pid = fork()) > 0)
	{
		close(fd[0]);
		write(fd[1], msgout, MSGSIZE);
		close(fd[1]);
	}    
	else if (pid == 0) 
	{
		close(fd[1]);
		read(fd[0],msgin,MSGSIZE);
		close(fd[0]);
		puts(msgin);
	}
	else
	{
		perror("fork()");
		exit(2);
	}
}
