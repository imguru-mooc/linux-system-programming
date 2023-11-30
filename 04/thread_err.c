#if 1
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "errors.h" 

void *foo(void* data)
{
	DPRINTF("foo(%p)\n", data);
	return 0;
}

int main()
{
	int ret;
	pthread_t thread = 0;
	pthread_create(&thread, 0, foo, (void*)0x777 );
	DPRINTF("thread=%ld\n", thread);
	ret = pthread_join( thread, 0 );
	if( ret > 0 )
		err_abort(ret, "pthread_join()");
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void *foo(void* data)
{
	return 0;
}

int main()
{
	int ret;
	pthread_t thread = 0;
	//pthread_create(&thread, 0, foo, 0 );
	printf("thread=%ld\n", thread);
	ret = pthread_join( thread, 0 );
	printf("ret=%d\n", ret );
	if( ret > 0 )
	{
		//printf("errno=%d\n", errno );
		printf("strerror=%s\n", strerror(ret) );
	}
	return 0;
}
#endif










