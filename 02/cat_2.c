#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main( int argc, char **argv)
{
	int fd;
	int ret;
	char buff[1024];

	fd = open( argv[1], O_RDONLY );
	printf("fd=%d\n", fd );
	while( ret = read( fd, buff, sizeof buff) ) 
		write( 1, buff, ret );
	close(fd);
	return 0;
}
