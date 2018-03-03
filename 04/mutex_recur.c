#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
pthread_mutexattr_t attr;

int main()
{
	pthread_mutexattr_init( &attr );
	pthread_mutexattr_settype( &attr , PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init( &mutex , &attr );

	pthread_mutex_lock( &mutex );  // 1
	pthread_mutex_lock( &mutex );  // 2
	printf("임계영역 진입\n");
	pthread_mutex_unlock( &mutex ); // 1
	pthread_mutex_unlock( &mutex ); // 0
	return 0;
}

