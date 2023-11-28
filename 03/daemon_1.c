#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

int daemon_init(void){
	pid_t   pid;
	int i;
	if(fork() > 0)
		exit(0); 
	setsid();               /* become session leader */
	chdir("/");             /* change working directory */
	umask(0);               /* clear our file mode creation mask */

	for(i=0;i<64;i++)
		close(i);
	signal(SIGCLD,SIG_IGN);
	return(0);
}

int main(void)
{
	daemon_init();
	//sleep(1000);
	//printf("daemon\n");
	syslog(1, "%s\n", "daemon");
	while(1)
		;
	return 0;
}

