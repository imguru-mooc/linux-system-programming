#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int flag;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond   = PTHREAD_COND_INITIALIZER;
void *producer(void *data)
{
	pthread_mutex_lock(&mutex);
	sleep(3);
	printf("디코딩 완료\n");
	flag = 10;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
	return 0;
}
void *consumer(void *data)
{
	pthread_mutex_lock(&mutex);
	pthread_cond_wait( &cond, &mutex);
	printf("동영상 플레이 시작, flag=%d\n", flag);
	pthread_mutex_unlock(&mutex);
	return 0;
}
int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, producer, 0);
	pthread_create(&thread[1], 0, consumer, 0);
	pthread_join( thread[0], 0 );
	pthread_join( thread[1], 0 );
	return 0;
}
