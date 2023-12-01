#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>

int main()
{
	char buff[1];
	int ret;
	int fd;
	int i;

	int epoll_fd;
	int nevent;
	struct epoll_event events[2];

	epoll_fd = epoll_create(1024);
	struct epoll_event event;

	fd = open("myfifo", O_RDWR);
	fcntl(fd, F_SETFL, O_NONBLOCK);

	event.data.fd = 0;
	event.events = EPOLLIN;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event);

	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);

	while(1)
	{
		nevent = epoll_wait(epoll_fd, events, 2, -1);

		for( i=0; i<nevent; i++ )
		{
			if( events[i].data.fd==0 && events[i].events & EPOLLIN)
			{
				ret = read(0, buff, sizeof buff);
				buff[ret-1] = 0;
				printf("키보드 입력:[%s]\n", buff);
			}

			if( events[i].data.fd==fd && events[i].events & EPOLLIN)
			{   
				while(1)
				{
					// "hello\n" => "ello\n"
					ret = read(fd, buff, sizeof buff);
					if(ret > 0 )
						write(1,buff,ret);
					else if(ret < 0 )
					{
						if(errno == EAGAIN )
							break;
					}
				}
			}
		}
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>

int main()
{
	char buff[1024];
	int ret;
	int fd;
	int i;

	int epoll_fd;
	int nevent;
	struct epoll_event events[2];

	epoll_fd = epoll_create(1024);
	struct epoll_event event;

	fd = open("myfifo", O_RDWR);

	event.data.fd = 0;
	event.events = EPOLLIN;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event);

	event.data.fd = fd;
	event.events = EPOLLIN;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);

	while(1)
	{
		nevent = epoll_wait(epoll_fd, events, 2, -1);

		for( i=0; i<nevent; i++ )
		{
			if( events[i].data.fd==0 && events[i].events & EPOLLIN)
			{
				ret = read(0, buff, sizeof buff);
				buff[ret-1] = 0;
				printf("키보드 입력:[%s]\n", buff);
			}

			if( events[i].data.fd==fd && events[i].events & EPOLLIN)
			{
				ret = read(fd, buff, sizeof buff);
				buff[ret-1] = 0;
				printf("myfifo 입력:[%s]\n", buff);
			}
		}
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <poll.h>
int main()
{
	char buff[1024];
	int ret;
	int fd;

	int nfds;
	struct pollfd fds[2]={0,};

	fd = open("myfifo", O_RDWR);

	while(1)
	{
		fds[0].fd = 0;
		fds[0].events = POLLIN;
		fds[1].fd = fd;
		fds[1].events = POLLIN;

		nfds = 2;

        poll(fds, nfds, -1);

		if(fds[0].revents & POLLIN)
		{
			ret = read(0, buff, sizeof buff);
			buff[ret-1] = 0;
			printf("키보드 입력:[%s]\n", buff);
		}

		if(fds[1].revents & POLLIN)
		{
			ret = read(fd, buff, sizeof buff);
			buff[ret-1] = 0;
			printf("myfifo 입력:[%s]\n", buff);
		}
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
	char buff[1024];
	int ret;
	int fd;

	int nfds;
	fd_set readfds;

	fd = open("myfifo", O_RDWR);
	nfds = fd+1;

	while(1)
	{
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(fd, &readfds);

		select(nfds, &readfds, 0, 0, 0);

		if( FD_ISSET(0, &readfds) )
		{
			ret = read(0, buff, sizeof buff);
			buff[ret-1] = 0;
			printf("키보드 입력:[%s]\n", buff);
		}

		if( FD_ISSET(fd, &readfds) )
		{
			ret = read(fd, buff, sizeof buff);
			buff[ret-1] = 0;
			printf("myfifo 입력:[%s]\n", buff);
		}
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
	char buff[1024];
	int ret;
	int fd;

	fd = open("myfifo", O_RDWR);

	fcntl(0, F_SETFL, O_NONBLOCK);
	fcntl(fd, F_SETFL, O_NONBLOCK);

	while(1)
	{
		ret = read(0, buff, sizeof buff);
		if( ret >=0 )
		{
			buff[ret-1] = 0;
			printf("키보드 입력:[%s]\n", buff);
		} 
		else if( ret < 0 )
		{
			if( errno != EAGAIN )
			{
				perror("read()");
				exit(0);
			}
		}

		ret = read(fd, buff, sizeof buff);
		if( ret >=0 )
		{
			buff[ret-1] = 0;
			printf("myfifo 입력:[%s]\n", buff);
		}
		else if( ret < 0 )
		{
			if( errno != EAGAIN )
			{
				perror("read()");
				exit(0);
			}
		}
	}
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	char buff[1024];
	int ret;
	int fd;

	fd = open("myfifo", O_RDWR);

	while(1)
	{
		ret = read(0, buff, sizeof buff);
		buff[ret-1] = 0;
		printf("키보드 입력:[%s]\n", buff);

		ret = read(fd, buff, sizeof buff);
		buff[ret-1] = 0;
		printf("myfifo 입력:[%s]\n", buff);
	}
	return 0;
}
#endif
