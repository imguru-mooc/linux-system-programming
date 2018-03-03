#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	mknod( "mydev", 0666 | S_IFCHR , 3<<8 | 1);
	getchar();
	unlink( "mydev" );
	return 0;
}
