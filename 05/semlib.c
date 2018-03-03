#include "semlib.h"
int CreateSEM(key_t semkey)
{
	int status=0,semid;

	/* semget() : Return nonnegative int if OK, -1 on error  */
	if((semid = semget(semkey,1,SEMPERM|IPC_CREAT|IPC_EXCL))==-1)
	{
		if(errno==EEXIST)
			semid = semget(semkey,1,0);
	}
	else
		/* semctl() : Return 0 id OK, -1 on error */
		status = semctl(semid,0,SETVAL,2);

	if(semid==-1 || status==-1)
		return -1;
	return semid;
}

int p(int semid)
{
	struct sembuf p_buf;

	p_buf.sem_num = 0;
	p_buf.sem_op  = -1;
	p_buf.sem_flg = SEM_UNDO;

	/* semop : Return : 0 if OK, -1 on error */
	if(semop(semid,&p_buf,1)==-1)
		return -1;
	return 0;
}

int v(int semid)
{
	struct sembuf p_buf;

	p_buf.sem_num = 0;
	p_buf.sem_op  = 1;
	p_buf.sem_flg = SEM_UNDO;

	/* semop : Return : 0 if OK, -1 on error */
	if(semop(semid,&p_buf,1)==-1)
		return -1;

	return 0;
}


