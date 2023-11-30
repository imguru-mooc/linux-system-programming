#if 1
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

sigjmp_buf env;
void alm(int signo)
{
	printf("SIGALRM Receive");
	siglongjmp(env, 1);
}  

int main()
{
	int ret;
	char buff[100];
	int n=3, i;

	signal( SIGALRM, alm );
	for(i=0; i<n; i++)
	{
		printf("%d번째 유저 배팅 요청:\n", i+1);
		ret = sigsetjmp(env, 32);
		printf("ret=%d\n", ret );
		if( ret == 0 )
		{
			alarm(5);
			ret = read(0, buff, sizeof buff);
			buff[ret-1] = 0;	
			printf("%s 배팅 완료\n", buff);
			alarm(0);
		}
		else if( ret == 1 )
		{
			printf("배팅 시간이 만료 되었습니다.\n");
		}
	}
	return 0;
}
#endif

#if 0
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void foo(void)
{
	int ret;
	char buff[100];
	ret = open("aaa", O_RDONLY);    
	if(ret<0)
		longjmp(env, 1);
	ret = read(-1, buff, sizeof buff);
	if(ret<0)
		longjmp(env, 2);
}

int main()
{
	int ret;
	ret = setjmp(env);
	printf("ret=%d\n", ret );
	if( ret == 0 )
		foo();
	else if( ret == 1 )
	{
		perror("open()");
		exit(0);
	}
	else if( ret == 2 )
	{
		perror("read()");
		exit(0);
	}

	return 0;
}
#endif

#if 0
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void foo(void)
{
	int ret;
	char buff[100];
	ret = open("aaa", O_RDONLY);    
//	if( ret < 0 )     
//		goto err;

	ret = read(-1, buff, sizeof buff);
//	if( ret < 0 )
//		goto err;
}

int main()
{
	foo();
	return 0;
err: 
	perror("");
	exit(0);
}
#endif

#if 0
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int ret;
	char buff[100];
	ret = open("aaa", O_RDONLY);
	if( ret < 0 )
		goto err;

	ret = read(-1, buff, sizeof buff);
	if( ret < 0 )
		goto err;
	return 0;

err: 
	perror("");
	exit(0);
}
#endif

#if 0
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void alm(int signo)
{
	printf("SIGALRM Receive");
	printf("timeout\n");
}  

int main()
{
	int ret;
	char buff[100];
	while(1)
	{
		alarm(5);
		ret = read(0, buff, sizeof buff);
		buff[ret-1] = 0;	
		printf("%s 배팅 완료\n", buff);
		alarm(0);
	}
	return 0;
}
#endif
