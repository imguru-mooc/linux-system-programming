#if 1
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd, i;
	int ret;
	char buff[1024];

	fd = open("myfifo", O_RDWR);
	printf("fd=%d\n", fd );

	for(i=0; ; i++)
	{
		write(fd, "h", 1);
		printf("%d\n", i );
	}
	return 0;
}
#endif

#if 0
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd;
	int ret;
	char buff[1024];

	fd = open("myfifo", O_RDWR);
	printf("fd=%d\n", fd );

	while(1)
	{
		ret = read(fd, buff, sizeof buff);
		write(1, buff, ret);
	}
	return 0;
}
#endif
