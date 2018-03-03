#include <stdio.h>

void swap(int, int);

int main(int argc, char **argv)
{
	int i, j;

	i=9;
	j=17;
	printf("Original value: i = %d, j = %d\n", i, j);
	swap(i, j);
	printf("Swapped value: i = %d, j = %d\n", i, j);

	return 0;
}

void swap(int a, int b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

