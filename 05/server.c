#include 	<stdio.h>
#include 	<string.h>
#include 	<unistd.h>
#include 	<fcntl.h>
#define 	MAXBUFF 	1024
void server(int readfd, int writefd)
{
	char 	buff[MAXBUFF];
	int 	n, fd;  extern int errno;

	if ((n = read(readfd, buff, MAXBUFF)) <= 0)	/* 파일 이름 수신 */
		printf("server: filename read error");
	buff[n] = '\0';
	if ((fd = open(buff, 0)) < 0) {
		strcat(buff, " can’t open\n");  
		n = strlen(buff);
		if(write(writefd, buff, n) != n)		/* 에러 메시지 전송 */
			printf("server: errmesg write error");
	} 	else {
		while((n = read(fd, buff, MAXBUFF)) > 0)
			if(write(writefd, buff, n) != n)	/* 파일 데이터 전송 */
				printf("server: data write error");
	}
}
