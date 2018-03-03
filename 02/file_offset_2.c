#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1, fd2;
	int ret;
	char buff[100];
	fd1 = open("aaa", O_RDONLY );
	fd2 = open("aaa", O_RDONLY );
	ret = read( fd1, buff, 2 );
	write( 1, buff, ret );
	ret = read( fd2, buff, 2 );
	write( 1, buff, ret );
	close(fd1);
	close(fd2);
	return 0;
}
