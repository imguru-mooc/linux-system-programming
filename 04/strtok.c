#if 1
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *my_handler1(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	pthread_mutex_lock(&mutex);
	p = strtok( hp, "-");
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok( 0, "-");
	}
	pthread_mutex_unlock(&mutex);
}
void *my_handler2(void *data)
{
	char ip[] = "192.168.1.100";
	char *p;
	pthread_mutex_lock(&mutex);
	p = strtok( ip, ".");
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok( 0, ".");
	}
	pthread_mutex_unlock(&mutex);
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
#include <unistd.h>
#include <pthread.h>
void *my_handler1(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	p = strtok( hp, "-");
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok( 0, "-");
	}
}
void *my_handler2(void *data)
{
	char ip[] = "192.168.1.100";
	char *p;
	p = strtok( ip, ".");
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok( 0, ".");
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
	p = strtok( hp, "-");
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0, "-");
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
	p = strtok( hp, "-");
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0, "-");
	}
	return 0;
}
#endif
