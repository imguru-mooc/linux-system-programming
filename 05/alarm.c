#if 0
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
}

int main()
{
	unsigned int ret;
	signal( SIGALRM, my_sig );
	alarm(10);
	sleep(3);
	ret = alarm(0);
	printf("ret=%u\n", ret );
	while(1);
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
}

int main()
{
	unsigned int ret;
	signal( SIGALRM, my_sig );
	alarm(10);
	sleep(3);
	ret = alarm(3);
	printf("ret=%u\n", ret );
	while(1);
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	alarm(1);
}

int main()
{
	signal( SIGALRM, my_sig );
	alarm(1);
	while(1);
	return 0;
}
#endif
