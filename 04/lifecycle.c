#include <pthread.h>
#include <unistd.h>
#include "errors.h"
void *thread_routine( void * arg ){
	while(1)
	{
		sleep(1);
		printf("child\n");
	}
	return 0;
}

int main( int argc, char **argv ){
	pthread_t thread_id;
	void *thread_result;
	int status;

	DPRINTF( "hello\n" );  
	status = pthread_create( &thread_id,0,thread_routine,0);
	if( status != 0 )
		err_abort( status, "Create thread");

	/*
	status = pthread_join( thread_id, &thread_result );
	if( status != 0 )
		err_abort( status, "Join thread");
	if( thread_result == 0 )
		DPRINTF("자식 쓰레드 종료\n");
		*/

	pthread_exit(0);
	printf("main : after\n");
	return 0;
}

