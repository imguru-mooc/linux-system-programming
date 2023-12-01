#if 1

#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int nfds=1;
	int ret;
	char buff[1024];
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(0, &readfds);

	select(nfds, &readfds, 0, 0, 0);
	ret = read(0, buff, sizeof buff);
	buff[ret-1] = 0;
	printf("[%s]\n", buff);

	return 0;
}
#endif
#if 0

#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int nfds=1;
	int ret;
	char buff[1024];
	fd_set readfds;
	struct timeval timeout;
	timeout.tv_sec  = 3;
	timeout.tv_usec = 500000;

	while(1)
	{
		timeout.tv_sec  = 3;
		timeout.tv_usec = 500000;
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		ret = select(nfds, &readfds, 0, 0, &timeout);
		if( ret == 0 )
			printf("입력 시간이 만료 되었습니다.\n");
		else if( ret > 0 )
		{
			ret = read(0, buff, sizeof buff);
			buff[ret-1] = 0;
			printf("[%s]\n", buff);
		}
	}

	return 0;
}
#endif

#if 0

#include <sys/select.h>
#include <stdio.h>
int main()
{
	int nfds=1;
	fd_set readfds;
	struct timeval timeout;
	timeout.tv_sec  = 3;
	timeout.tv_usec = 500000;

	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	select(nfds, &readfds, 0, 0, &timeout);
	printf("after\n");

	return 0;
}
#endif
