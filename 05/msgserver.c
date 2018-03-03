#include "msglib.h"
#include <stdio.h> 
#include <string.h> 
int main()
{
	int qid;
	MSG_t msg;

	long mtype;

	qid=CreateMQ(5000);

	if(qid<0)
	{
		printf("q open fail: %d\n",errno);	
		return -1;
	}
	while(1)
	{
		mtype = RecvMQ(qid, 1L,&msg);

		if(mtype > 0)
		{
			if(!strcmp(msg.mtext, "exit"))
			{
				printf("Server Process Exit\n");	
				break;
			}
			printf("recv : %s\n",msg.mtext);	
			if(SendMQ(qid, mtype, msg)<0)
				break;
		}
	}
	RemoveMQ(qid);

	return 0;
}

