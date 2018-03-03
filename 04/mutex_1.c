#include <pthread.h>
#include <stdio.h>

int sum=0;
void * foo(void *data)
{
	int local;
	int i;

	for( i=0; i<10000000; i++ )
	{
		local = sum ;
		local = local+1;
		sum = local;
	}
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0 );
	pthread_create(&thread[1], 0, foo, 0 );
	pthread_join(thread[0], 0 );
	pthread_join(thread[1], 0 );
	printf("sum=%d\n", sum );
	return 0;
}
