#if 1
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * foo( void *data )
{
	printf("child\n");
	sleep(3);
	return 0;
}

int main()
{
	pthread_t thread;

	pthread_create(&thread, 0, foo, 0);

	pthread_join(thread, 0);

	printf("parent\n");
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	pid = fork();

	if( pid == 0 )
	{
		printf("child\n");
		sleep(3);
		exit(7);
	}
	wait(0);

	printf("parent\n");
	return 0;
}
#endif


