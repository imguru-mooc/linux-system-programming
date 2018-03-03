#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void alm(int signo)
{
	printf("SIGALRM Receive");
}  

void main()
{
	signal(SIGALRM, alm);
	alarm(10);
	printf("process id pause\n");
	pause();
	printf("process is wakeup\n");
}

