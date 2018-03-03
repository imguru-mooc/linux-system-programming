#include <pthread.h>
#include <stdio.h>

#define  MAX_THREAD   2
int sum = 0;
void *thread_routine( void * arg )
{
	int i;
	for(i=0; i<1000000000/MAX_THREAD; i++ )
	{
		++sum;
	}
	return arg;
}

int main( int argc, char **argv )
{
	pthread_t thread_id[MAX_THREAD];
	void *thread_result;
	int status, i;

	for(i=0; i<MAX_THREAD ; i++ )
		status = pthread_create( &thread_id[i],0,thread_routine,0);

	for(i=0; i<MAX_THREAD ; i++ )
		status = pthread_join( thread_id[i], &thread_result );

	printf("sum=%d\n", sum);
	return 0;  
}

