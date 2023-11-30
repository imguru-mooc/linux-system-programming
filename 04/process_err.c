#if 1
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void err_exit(char *msg)
{
	perror(msg);
	exit(1);
}

int Open(const char *pathname, int flags)
{
	int fd;
	fd = open(pathname, flags);
	if( fd < 0 )
		err_exit("open()");
	return fd;
}

int main()
{
	int fd;
	char buffer[1024];
	fd = Open("aaa", O_RDONLY);
	printf("after\n");
	read(fd, buffer, sizeof buffer);
	return 0;
}
#endif

#if 0
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void err_exit(char *msg)
{
	perror(msg);
	exit(1);
}

int main()
{
	int fd;
	char buffer[1024];
	fd = open("aaa", O_RDONLY);
	if( fd < 0 )
		err_exit("open()");
	printf("after\n");
	read(fd, buffer, sizeof buffer);
	return 0;
}
#endif

#if 0
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
	int fd;
	char buffer[1024];
	fd = open("aaa", O_RDONLY);
	if( fd < 0 )
	{
		perror("open()");
		exit(1);
	}
	printf("after\n");
	read(fd, buffer, sizeof buffer);
	return 0;
}
#endif
#if 0
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main()
{
	int fd;
	fd = open("aaa", O_RDONLY);
	printf("fd=%d\n", fd );
	if( fd < 0 )
		//printf("open(), strerror=%s\n", strerror(errno));
		perror("open()");
	return 0;
}
#endif

#if 0
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main()
{
	int fd;
	fd = open("aaa", O_RDONLY);
	printf("fd=%d\n", fd );
	if( fd < 0 )
		printf("errno=%d\n", errno);
		printf("strerror=%s\n", strerror(errno));
	return 0;
}
#endif

#if 0
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	fd = open("aaa", O_RDONLY);
	printf("fd=%d\n", fd );
	return 0;
}
#endif
