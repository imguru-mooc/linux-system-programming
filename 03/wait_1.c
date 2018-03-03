#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
	int status;
	if(fork()==0)
		exit(2);

	wait(&status);
	if( (status & 0xff) == 0 )
		printf("정상종료 : exit(%d)\n", (status>>8)&0xff );
	return 0;
}
