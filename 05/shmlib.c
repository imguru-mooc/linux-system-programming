#include "shmlib.h"
int CreateSHM(long key)
{
	return( shmget(key, sizeof(SHM_t),IPC_CREAT | 0777) );
}

int OpenSHM(long key)
{
	return( shmget(key, sizeof(SHM_t), 0) );
}

SHM_t *GetPtrSHM(int shmid)
{
	return( (SHM_t *)shmat(shmid,(char *)0,0) );
}

int FreePtrSHM(SHM_t *shmptr)
{
	return( shmdt((char *)shmptr) );
}

int RemoveSHM(int shmid)
{
	return( shmctl(shmid,IPC_RMID,(struct shmid_ds *)0) );
} 


