#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

/*
void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo );
	while( waitpid(-1, 0, WNOHANG) > 0 )
		;
}
*/
int signal_fd;
int signal_recv_fd;
void my_sig(int signo)
{
	char s='W';
	write(signal_fd, &s, 1);
}
int main()
{
	pid_t pid;
	int i;
	int fd[2];
	char ch;

	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = my_sig;
	act.sa_flags = SA_NOCLDSTOP;
	sigaction(SIGCHLD, &act, 0);

	socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
    signal_fd = fd[0];
	signal_recv_fd = fd[1];
	pid = fork(); 
	if( pid == 0 )
	{
		for(i=0; i<3; i++ )
		{
			printf("\t\t\tchild\n");
			sleep(1);
		}
		exit(7);
	}
	while(1)
	{
		read( signal_recv_fd,  &ch , 1 );
	    while( waitpid(-1, 0, WNOHANG) > 0 )
		    ;
		printf("자식 프로세스 수거\n");
		sleep(1);
	}
	return 0;
}
