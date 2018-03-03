#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MSGSIZE 16

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

int main()
{  
	char inbuf[1024];
	int p[2], j;
	int ret;

	if (pipe(p) < 0) {
		perror("pipe call");
		exit(1);
	}
	/* write down pipe */
	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);

	while(1)
	{
		ret = read(p[0], inbuf, 10);
		write( 1, inbuf, ret );
		getchar();
	}
	return 0;
}

