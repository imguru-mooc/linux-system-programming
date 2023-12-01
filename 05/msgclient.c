#include "msglib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int qid,st;
	MSG_t msg;
	pid_t child_pid;

	qid = OpenMQ(5000);

	if(qid < 0)
	{
		printf("q open fail: %d\n",errno);	
		return -1;
	}

	if((child_pid=fork())>0)
	{
		while(1) {
			memset(msg.mtext,'\0',100); 
			fgets(msg.mtext, sizeof msg.mtext, stdin);
			msg.mtext[strlen(msg.mtext)-1] = 0; // '\n' => '\0'

			if(SendMQ(qid,1L,msg)<=0)   {
				printf("q send fail: %d\n",errno);	
				break;
			}

			if(!strcmp(msg.mtext, "exit"))    {
				kill(child_pid, 2);
				printf("Client Process Exit\n");	
				wait(0);
				break;
			}
		}
	}
	else
	{
		while(1) {
			st = RecvMQ(qid, getppid(),&msg);
			if(st>0)
				printf("recv : %s\n", msg.mtext);
		}
	}
	return 0;
}

