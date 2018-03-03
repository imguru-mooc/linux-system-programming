#include <sys/ipc.h>
#include <sys/shm.h>
typedef struct 
{
	int count;
	char name[256];
} SHM_t;
int CreateSHM(long key);
int OpenSHM(long key);
SHM_t *GetPtrSHM(int shmid);
int FreePtrSHM(SHM_t *shmptr);
int RemoveSHM(int shmid);


