#include <stdio.h>
#include <unistd.h>
int main()
{
	fork(); 
	printf("after\n");
	return 0;
}
