#if 1
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void foo(int *count)
{
	printf("count=%d\n", ++*count );
}

void *my_handler1(void *data)
{
	int count=0;
	foo(&count);
	foo(&count);
}

void *my_handler2(void *data)
{
	int count=0;
	foo(&count);
	foo(&count);
	foo(&count);
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
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void foo(void)
{
	static int count=0; 
	printf("count=%d\n", ++count );
}

void *my_handler1(void *data)
{
	foo();
	foo();
}

void *my_handler2(void *data)
{
	foo();
	foo();
	foo();
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













