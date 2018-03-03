#include 	<stdio.h>
#include 	<string.h>
#include 	<unistd.h>
#include 	<fcntl.h>
#define 	MAXBUFF 	1024
void client(int readfd, int writefd){
	char 	buff[MAXBUFF];
	int 	n;

	if(fgets(buff, MAXBUFF, stdin) == NULL)
		printf("client: filename read error");
	n = strlen(buff);
	if(buff[n-1] == '\n')
		n--;
	if(write(writefd, buff, n) != n)			/* 파일 이름 전송 */
		printf("client: filename write error");

	while((n = read(readfd, buff, MAXBUFF)) > 0)	/* 파일 데이터 수신 */
		if(write(1, buff, n) != n)
			printf("client: data write error");
	if(n < 0)
		printf("client: data read error");
}

