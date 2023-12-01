#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) 
{
	int fd[2],pid;
	if (pipe(fd) == -1)
	{
		perror("pipe()");
		exit(1);
	}
	if ((pid = fork())==0)
	{
		close(fd[1]);
		dup2(fd[0],0);  // close(0), fd_array[0] = fd_array(fd[0])
		execlp(argv[2],argv[2], (char *)0);
	}
	close(fd[0]);
	dup2(fd[1],1);  // close(1), fd_array[1] = fd_array(fd[1])
	execlp(argv[1],argv[1],(char *)0);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ./a.out   who    sort
// argv[0] argv[1] argv[2]
int main(int argc, char **argv) 
{
	int fd[2],pid;

	if( argc != 3 )
	{
		printf("usage : a.out who sort\n");
		exit(0);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe()");
		exit(1);
	}
	if ((pid = fork())==0)
	{
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);
		execlp(argv[2],argv[2], (char *)0);
	}
	close(fd[0]);
	close(1);
	dup(fd[1]);
	close(fd[1]);
	execlp(argv[1],argv[1],(char *)0);
}
#endif



