#include "semlib.h"
#include <stdio.h>

int main()
{
    int semid;
	semid = CreateSEM(5000);
	p(semid);
	printf("임계영역 진입\n");
	getchar();
	v(semid);
	printf("임계영역 탈출\n");
	return 0;
}
