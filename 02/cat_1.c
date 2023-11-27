#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// # ./a.out xxx
int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buff[100];

	fd = open(argv[1], O_RDONLY);

	while(ret = read(fd, buff, sizeof buff))
		write( 1, buff, ret );

	close(fd);
	return 0;
}
