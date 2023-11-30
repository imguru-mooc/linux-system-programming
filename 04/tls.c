#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_key_t key;
pthread_once_t once_control;

void my_destructor(void* data)
{
	printf("my_destructor(%p)\n", data );
	free(data);
}

void init_routine(void)
{
	printf("init_routine()\n" );
	pthread_key_create( &key, my_destructor);
	printf("key=%d\n", key);
}


void foo(void)
{
	void *tsd;
	pthread_once(&once_control, init_routine);
    tsd = pthread_getspecific(key);
    if ( tsd == NULL ) {
        tsd = calloc(1, sizeof(int));     
		printf("after :  tsd=%p\n", tsd);
        pthread_setspecific(key, tsd);
    }
}

void* my_handler(void *data)
{
	foo();
	foo();
	foo();
	return 0;
}

#define MAX 5 
int main()
{
	int i;
	pthread_t thread[MAX];

	for(i=0; i<MAX; i++)
		pthread_create(&thread[i], 0, my_handler, 0);

	for(i=0; i<MAX; i++)
		pthread_join(thread[i],0);
	return 0;
}








