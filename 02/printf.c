#include <stdio.h>
#include <unistd.h>

int main()
{
	//printf("hello");
	//write(1, "hello", 5);
	fprintf(stderr, "hello");
	sleep(3);
	return 0;
}
