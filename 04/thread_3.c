#include <stdio.h>
#include <pthread.h>

void *foo(void *data)
{
	printf("child : local=%d\n", ++*(int*)data);
	return 0;
}

int main()
{
	int local=10;
	pthread_t thread;
	pthread_create(&thread, 0, foo, &local);
	//foo(&local);
	pthread_join( thread, 0 );
	printf("parent: local=%d\n", local);
	return 0;
}
