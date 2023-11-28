#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
	int status;
	if(fork()==0)
		while(1);

	wait(&status);
	if( (status & 0x7f) == 0 )
		printf("정상종료 : exit(%d)\n", (status>>8)&0xff );
	else
	{
		printf("비정상종료 : signo(%d) %s\n", status&0x7f,
				(status&0x80)?"(core dumped)":"" );
	}
	return 0;
}
