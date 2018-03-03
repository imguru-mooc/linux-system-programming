#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
void term_stat( int status )
{
	if( WIFEXITED(status) )
		printf("정상종료 : exit(%d)\n", WEXITSTATUS(status) );
	else if( WIFSIGNALED(status) )
	{
		printf("비정상종료 : signo(%d) %s\n", WTERMSIG(status),
				(WCOREDUMP(status))?"(core dumped)":"" );
	}
}
int main()
{
	int status;
	if(fork()==0)
		while(1);

	wait(&status);
	term_stat(status);
	return 0;
}
