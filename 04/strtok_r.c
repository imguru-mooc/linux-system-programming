#if 1
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void *my_handler1(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	char *saveptr;
	p = strtok_r( hp, "-", &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok_r( saveptr, "-", &saveptr);
	}
}
void *my_handler2(void *data)
{
	char ip[] = "192.168.1.100";
	char *p;
	char *saveptr;
	p = strtok_r( ip, ".", &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok_r( saveptr, ".", &saveptr);
	}
}
int main()
{
	pthread_t tid1, tid2;
	pthread_create( &tid1, 0, my_handler1, 0 );
	pthread_create( &tid2, 0, my_handler2, 0 );
	pthread_join( tid1, 0 );
	pthread_join( tid2, 0 );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>
void *my_handler(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	char *saveptr;
	p = strtok_r( hp, "-", &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok_r( saveptr, "-", &saveptr);
	}
}
int main()
{
	pthread_t tid;
	pthread_create( &tid, 0, my_handler, 0 );
	pthread_join( tid, 0 );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	char hp[] = "010-1234-5678";
	char *p;
	char *saveptr;
	p = strtok_r( hp, "-", &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok_r( saveptr, "-", &saveptr);
	}
	return 0;
}
#endif











