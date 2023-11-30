#if 1
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
	while( ret = read( fd[0], buff, 1 ) )
	{
		buff[ret] = 0;
		printf("[%s]\n", buff );
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd[2];

	//fd = open("aaa", O_RDONLY);
	pipe(fd);
	printf("fd[0]=%d\n", fd[0]);
	printf("fd[1]=%d\n", fd[1]);
	
	return 0;
}
#endif
