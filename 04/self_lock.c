#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *foo(void *data)
{
	int ret;
	ret = pthread_mutex_lock( &mutex );
	printf("임계영역 진입 1. : ret=%d\n", ret);
	ret = pthread_mutex_lock( &mutex );
	printf("임계영역 진입 2. : ret=%d\n", ret);
	pthread_mutex_unlock( &mutex );
	return 0;
}

int main()
{
	int ret;
	pthread_t thread;
	//pthread_mutex_init( &mutex , 0 );

	//pthread_create(&thread, 0, foo, 0 );
	//pthread_join(thread, 0);
	ret = pthread_mutex_lock( &mutex );
	printf("임계영역 진입 1. : ret=%d\n", ret);
	ret = pthread_mutex_lock( &mutex );
	printf("임계영역 진입 2. : ret=%d\n", ret);
	pthread_mutex_unlock( &mutex );
	return 0;
}

