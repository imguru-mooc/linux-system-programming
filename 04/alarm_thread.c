#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

typedef struct alarm_tag{
	int seconds;
	char message[64];
} alarm_t;

void* alarm_thread(void *data)
{
	alarm_t *alarm = (alarm_t *)data;
	pthread_detach(pthread_self());
	sleep(alarm->seconds);
	printf("(%d) %s\n", alarm->seconds, alarm->message );
	return 0;
}

int main()
{
	pthread_t thread;
	alarm_t *alarm;
	char line[128];
	while(1)
	{
		alarm = malloc(sizeof(alarm_t));
		printf("Alarm>");
		fgets( line, sizeof line, stdin ); // "10 hello\n"
		sscanf( line, "%d %64[^\n]", &alarm->seconds, alarm->message ); 
		pthread_create( &thread, 0, alarm_thread, alarm );
	}
	return 0;
}
