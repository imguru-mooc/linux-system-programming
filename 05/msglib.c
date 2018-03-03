#include "msglib.h"

int CreateMQ(long key)
{
	return( msgget(key, IPC_CREAT | 0777) );
}

int OpenMQ(long key)
{
	return( msgget(key, 0) );
}

long SendMQ(int qid, long mtype, MSG_t msg)
{
	int st;

	msg.to_mtype = mtype;
	msg.fm_mtype = getpid();

	/* msgsnd() : Return 0 if OK, -1 on error */    
	st = msgsnd(qid, &msg, (sizeof(MSG_t)-sizeof(long)), IPC_NOWAIT);

	if(st < 0)
		return -1L;

	return msg.fm_mtype;
}

long RecvMQ(int qid, long mtype, MSG_t *msg)
{
	int st;

	/* msgrcv() : Return recv bytes if OK, -1 on error */
	st = msgrcv(qid, msg,sizeof(MSG_t)- sizeof(long), 
			mtype, IPC_NOWAIT);
	if(st < 0)
		return -1L;
	return msg->fm_mtype;
}

int GetFreeSizeMQ(int qid, long *freesize)
{
	int rtn;
	struct msqid_ds stat_q;

	if(qid<0)
		return -1;

	/* msgctl() : Return  0 if OK, -1 on error */
	rtn = msgctl(qid,IPC_STAT,&stat_q);
	if(rtn < 0)
		return -1;

	*freesize = stat_q.msg_qbytes - stat_q.msg_cbytes;

	return rtn;
}

int RemoveMQ(int qid)
{
    return(msgctl(qid, IPC_RMID, 0));
}

