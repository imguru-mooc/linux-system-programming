#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// # mkfifo myfifo

int main()
{
	int fd;
	char buff[1024];
	fd = open("myfifo", O_RDWR );
	getchar();
	write( fd, "he", 2 );
	getchar();
	write( fd, "ll", 2 );
	getchar();
	write( fd, "o\n", 2 );
	return 0;
}
