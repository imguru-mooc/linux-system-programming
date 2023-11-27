#include <stdio.h>
int main(int argc, char **argv)
{
	FILE *fp;
	int ch;
	int count=0;
	fp = fopen(argv[1], "r");
	while((ch = fgetc(fp)) != EOF) //  shift+k
		count++;
	printf("count=%d\n", count );
	fclose(fp);

	//open  // 2K
	return 0;
}
