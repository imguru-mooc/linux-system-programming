#include <stdio.h>
#include <pthread.h>

void *foo(void *data)
{
	printf("\t\tchild\n");
	return 0;
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, 0, foo, 0);
	pthread_join( thread, 0 );
	printf("parent\n");
	return 0;
}
