#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void sig(int sig) 
{
	printf("child die(%d)\n",getpid());
}

int main() 
{
	signal(SIGINT,sig);
	pause();
	return 0;
}
