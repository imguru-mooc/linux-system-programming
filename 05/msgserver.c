#include "msglib.h"
#include <stdio.h> 
#include <string.h> 
int main()
{
	int qid;
	MSG_t msg;
	int i;

	long mtype;

	long  client_list[10]={0,};
	int client_count=0;

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

			for(i=0; i< client_count; i++)
			{
				if(client_list[i]==mtype)
					break;
			}
			if( i>=client_count )
			{
				printf("새로운 접속자 %ld\n", mtype);
				client_list[client_count++]=mtype;
				printf("현재 접속자수 %d\n", client_count);
			}

			if(!strcmp(msg.mtext, "exit"))
			{
				for(i=0; i< client_count; i++)
				{
					if(client_list[i]==mtype)
						break;
				}

				printf("탈퇴한 접속자 %ld\n", mtype);
				client_list[i] = client_list[--client_count];
				printf("현재 접속자수 %d\n", client_count);
				continue;
			}
			printf("recv : %s\n",msg.mtext);	

			for(i=0; i< client_count; i++)
				SendMQ(qid, client_list[i], msg);
		}
	}
	RemoveMQ(qid);

	return 0;
}

