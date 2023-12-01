#include <stdio.h> 
int main(void)
{ 
	FILE *pipein_fp, *pipeout_fp; 
	char readbuf[80]; 

	/*popen() 호출을 사용하여 단방향 파이프를 만든다*/ 
	pipein_fp = popen("ls", "r"); 

	/*popen() 호출을 사용하여 단방향 파이프를 만든다*/ 
	pipeout_fp = popen("wc", "w"); 

	/*반복 처리*/
	while(fgets(readbuf, 80, pipein_fp)) 
		fputs(readbuf, pipeout_fp); 
	/*파이프를 닫는다*/ 
	pclose(pipein_fp); 
	pclose(pipeout_fp);

	return(0); 
} 

