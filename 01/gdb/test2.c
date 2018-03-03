#include <stdio.h>
#include <stdlib.h>

int sum(int, int);

int main(int argc, char **argv)
{
	int i;
	int j;
	int r;

	i = atoi(argv[1]);
	j = atoi(argv[2]);
	printf("Add from %d to %d\n", i, j);
	r = sum(i, j);
	printf("Sum = %d\n", r);

	return 0;
}

int sum(int from, int to)
{
	int i;
	int total = 0;

	for (i=from; i<to; i++) {
		total += i;
	}
	return total;
}


