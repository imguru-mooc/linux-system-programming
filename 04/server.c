#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// # mkfifo myfifo
ssize_t  readline(int fd, void *vptr, size_t maxlen);

int main()
{
	int fd, ret;
	char buff[1024];
	fd = open("myfifo", O_RDWR );
	while( ret=readline( fd, buff, sizeof buff) )
	//while( ret=read( fd, buff, sizeof buff) )
		write(1, buff, ret );

	return 0;
}
