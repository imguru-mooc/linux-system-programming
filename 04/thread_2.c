#include <stdio.h>
#include <pthread.h>

int global=6;
void *foo(void *data)
{
	printf("child : global=%d\n", ++global);
	printf("child : &global=%p\n", &global);
	return 0;
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, 0, foo, 0);
	pthread_join( thread, 0 );
	printf("parent: global=%d\n", global);
	printf("parent : &global=%p\n", &global);
	return 0;
}
