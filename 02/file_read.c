#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd;
	int ret;
	char buff[100];
	fd = open("aaa", O_RDONLY);
	ret = read( fd, buff, 2 );
	write( 1, buff, ret );
	ret = read( fd, buff, 2 );
	write( 1, buff, ret );
	close(fd);
	return 0;
}

