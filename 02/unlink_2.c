#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd, ret ;
	char buff[100];
	fd = open( "zzz", O_RDWR | O_CREAT| O_TRUNC, 0666);
	getchar();
	unlink("zzz");  // 이시점에서는 파일의 이름만 지워진다.
	getchar();
	write(fd, "hello\n", 6 );  // unlink 이후에도 파일에 쓸수 있다.
	lseek(fd, 0 , SEEK_SET );

	ret = read( fd, buff, sizeof buff ); 
	// unlink 이후에도 파일에서 읽을수 있다.
	write( 1, buff, ret );

	for(;;)
		;
	return 0;
}

