#include "shmlib.h"
#include <stdio.h>

int main()
{
	int shm_id, ret;
	SHM_t *shm;

	shm_id = CreateSHM(5000);
	shm = GetPtrSHM(shm_id);
	printf("server: shm=%p\n", shm);
	getchar();
	printf("%d, %s\n", shm->count, shm->name );
	return 0;
}

