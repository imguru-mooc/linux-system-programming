#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// # ./a.out xxx
int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buff[100];
	fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0666 );

	close(1);
	dup(fd);

	printf("hello world\n");
	close(fd);
	return 0;
}
