#include <stdio.h>
typedef int int32_t;
int __bionic_cmpxchg(int32_t old_value, int32_t new_value, 
		                      volatile int32_t* ptr)
{
	int32_t prev;
	__asm__ __volatile__ ("lock; cmpxchgl %1, %2"
			: "=a" (prev)
			: "q" (new_value), "m" (*ptr), "0" (old_value)
			: "memory");
	return prev != old_value;
}

int mutex=1;

void spin_lock(int *mutex)
{
	while(__bionic_cmpxchg( 0, 1, mutex));
}
int main()
{
	int ret = __bionic_cmpxchg( 0, 1, &mutex);
	printf("ret=%d, mutex=%d\n", ret, mutex); 

	//int ret = __bionic_cmpxchg( 0, 1, &mutex);
	//printf("ret=%d, mutex=%d\n", ret, mutex); 
	/*
	int ret;
	spin_lock(&mutex);
	printf("임계 영역 진입 1.\n");
	spin_lock(&mutex);
	printf("임계 영역 진입 2.\n");
	*/
	return 0;
}
