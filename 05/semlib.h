#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define SEMPERM 0666

int CreateSEM(key_t semkey);
int p(int semid);
int v(int semid);

