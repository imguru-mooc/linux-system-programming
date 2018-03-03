#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig){
	printf("signal no(%d) Received\n",sig);
}

int main()
{
	if(signal(SIGUSR1,handler)==SIG_ERR)    {
		fprintf(stderr,"cannot set USR1\n");
		exit(1);
	}                
	if(signal(SIGUSR2,handler)==SIG_ERR)  {
		fprintf(stderr,"cannot set USR2\n");
		exit(1);
	}
	for(;;)       
		pause();
	return 0;
} 

