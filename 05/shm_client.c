#include "shmlib.h"
#include <stdio.h>
#include <string.h>

int main()
{
	int shm_id, ret;
	SHM_t *shm;

	shm_id = OpenSHM(5000);
	shm = GetPtrSHM(shm_id);
	printf("client: shm=%p\n",  shm);
	shm->count = 1234;
	strcpy( shm->name, "공유메모리\n");
	getchar();
	return 0;
}

