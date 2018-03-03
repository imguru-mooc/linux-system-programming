#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutex;
int sum=1;
int foo(int i)
{
	if(i==0)
		return 1;
	pthread_mutex_lock( &mutex );
	printf("임계영역 진입\n");
	sum = i*foo(i-1);  // 5*foo(4)
	pthread_mutex_unlock( &mutex );
	return sum;
}

int main()
{
	pthread_mutex_init( &mutex , 0 );
	foo(5);
	printf("sum=%d\n", sum );
	return 0;
}

