#include <stdio.h>
#include <main.h>
#include <pthread.h>

void * foo(void *data)
{
	int ret;
	ret = add(3,4);
	printf("foo(), ret=%d\n", ret);
	return 0;
}

int main()
{
	int ret;
	pthread_t thread;
	pthread_create( &thread , 0, foo, 0 );
	pthread_join( thread , 0 );
	return 0;
}

