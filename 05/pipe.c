#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd[2];
	char buff[1024];
	int ret;

	pipe(fd);
	printf("fd[0]=%d\n", fd[0] );
	printf("fd[1]=%d\n", fd[1] );
	write( fd[1], "hello", 5 );
	ret = read( fd[0], buff, sizeof buff );
	buff[ret] = 0;
	printf("[%s]\n", buff );
	close(fd[0]);
	close(fd[1]);
	return 0;
}
