#if 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_key_t key;

void foo(void)
{
	int *tsd;
	tsd = pthread_getspecific(key);
	if( tsd == 0 )
	{
		tsd = calloc(1, sizeof(int));
		printf("tsd=%p\n", tsd );
	    pthread_setspecific(key, tsd);
	}
	printf("count=%d\n", ++*tsd );
}
//--------------------------------------------------------------
void *my_handler1(void *data)
{
	foo();
	foo();
	sleep(1);
}

void *my_handler2(void *data)
{
	foo();
	foo();
	foo();
	sleep(1);
}

void destructor(void* p)
{
	printf("destructor(%p)\n", p );
	free(p);
}

int main()
{
	pthread_t tid1, tid2;
	pthread_key_create( &key, destructor); 
	pthread_create( &tid1, 0, my_handler1, 0 );
	pthread_create( &tid2, 0, my_handler2, 0 );
	pthread_join( tid1, 0 );
	pthread_join( tid2, 0 );
	return 0;
}
#endif













