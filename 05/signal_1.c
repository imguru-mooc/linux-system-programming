#if 1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIGINT  (2)

typedef void (*handler_t)(int);

handler_t signal(int, handler_t);

void catchint(int signo)
{
	printf(" SIGINT Receive\n");
}  

int main()
{
	signal(SIGINT, catchint);

	printf("sleep call #1\n");      sleep(1);
	printf("sleep call #2\n");      sleep(1);
	printf("sleep call #3\n");      sleep(1);
	printf("sleep call #4\n");      sleep(1);
	printf("Exiting");
	return 0;
}
#endif

#if 0
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void catchint(int signo)
{
	printf(" SIGINT Receive\n");
}  

int main()
{
	signal(SIGINT,catchint);

	printf("sleep call #1\n");      sleep(1);
	printf("sleep call #2\n");      sleep(1);
	printf("sleep call #3\n");      sleep(1);
	printf("sleep call #4\n");      sleep(1);
	printf("Exiting");
	return 0;
}
#endif

